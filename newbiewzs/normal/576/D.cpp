#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string.h>
#include<vector>
#include<queue>
#include<map>
#include<ctime>
#include<set>
#include<bitset>
#define fi first
#define se second
#define mp make_pair
#define pii pair<int,int>
#define pb push_back
#define pil pair<int,long long>
#define pll pair<long long,long long>
#define vi vector<int>
#define vl vector<long long>
#define ci ios::sync_with_stdio(false)
//#define int long long
using namespace std;
typedef long long ll;
const int N=155;
int n,m;
struct node{
	int a,b,d;
}a[N];
int cmp(node x,node y){
	return x.d<y.d;
}
struct mat{
	bitset<155>a[155];
	friend mat operator * (mat x,mat y){
		mat z;
		for(int i=1;i<=n;i++){
			for(int k=1;k<=n;k++){
				if(x.a[i][k]){
					z.a[i]|=y.a[k];
				}
			}
		}
		return z;
	}
}d,pre;
mat ksm(mat x,int k){
	mat da;
	for(int i=1;i<=n;i++)da.a[i][i]=1;
	while(k){
		if(k&1)da=da*x;
		k>>=1;
		x=x*x;
	}
	return da;
}
int dis[155];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&a[i].a,&a[i].b,&a[i].d);
	}
	sort(a+1,a+m+1,cmp);
	pre.a[1][1]=1;
	int ans=2e9;
//	for(int i=1;i<=n;i++)d.a[i][i]=1;
	for(int i=1;i<=m;i++){
		pre=pre*ksm(d,a[i].d-a[i-1].d);
		queue<int>q;
		d.a[a[i].a][a[i].b]=1;
		for(int k=1;k<=n;k++){
			dis[k]=2e9;
			if(pre.a[1][k]){
				q.push(k);dis[k]=0;
			}
		}
		while(q.size()){
			int u=q.front();q.pop();
			for(int k=1;k<=n;k++){
				if(d.a[u][k] and dis[k]>1e9){
					dis[k]=dis[u]+1;
					q.push(k);
				}
			}
		}
		if(dis[n]<1e9){
			ans=min(ans,a[i].d+dis[n]);
		}
	}
	if(ans==2e9)puts("Impossible");
	else{
		printf("%d",ans);
	}
	return 0;
}