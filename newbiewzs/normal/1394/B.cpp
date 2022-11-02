#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string.h>
#include<vector>
#include<queue>
#include<map>
#include<ctime>
#include<bitset>
#include<set>
#include<math.h>
//#include<unordered_map>
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
typedef unsigned long long ull;
int read(){
	char c=getchar();
	ll x=1,s=0;
	while(c<'0'||c>'9'){
	   if(c=='-')x=-1;c=getchar();
	}
	while(c>='0'&&c<='9'){
	   s=s*10+c-'0';c=getchar();
	}
	return s*x;
}
const int N=2e5+55;
int n,m,s,x,y,z,ans,st[10],zs[10][N],in[N],bh[10][10],pd[10][10][10][10];
vector<pii>v[N];
bitset<N>f[10][10];
void dfs(int u){
	if(u==s+1){
		for(int i=1;i<=s;i++){
			if(bh[i][st[i]])return ;
			for(int k=1;k<=s;k++){
				if(i==k)continue;
				if(pd[i][st[i]][k][st[k]])return ;
			}
		}
		ans++;
		return ;
	}
	for(int i=1;i<=u;i++){
		st[u]=i;
		dfs(u+1);
	}
}
int main(){
	n=read();m=read();s=read();
	for(int i=1;i<=m;i++){
		x=read();y=read();z=read();
		v[x].pb(mp(z,y));
		in[x]++;
	}
	for(int i=1;i<=n;i++)sort(v[i].begin(),v[i].end());
	for(int i=1;i<=s;i++){
		memset(zs,0,sizeof(zs));
		for(int j=1;j<=n;j++){
			if(in[j]==i){
				for(int k=1;k<=i;k++){
			//		cout<<"seses"<<i<<" "<<j<<" "<<k<<endl;
			//		if(i==1 and j==2 and k==1){
			//			new char;
			//		}
					f[i][k][v[j][k-1].se]=1;
					if(zs[k][v[j][k-1].se]==1)bh[i][k]=1;
					zs[k][v[j][k-1].se]++;
				}
			}
		}
	}
	for(int i=1;i<=s;i++){
		for(int k=1;k<=s;k++){
			if(i==k)continue;
			for(int j=1;j<=i;j++){
				for(int l=1;l<=k;l++){
					if((f[i][j]&f[k][l]).count())pd[i][j][k][l]=1;
				}
			}
		}
	}
	dfs(1);
	cout<<ans;
	return 0;
}