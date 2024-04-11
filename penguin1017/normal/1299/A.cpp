#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define per(i,a,b) for(int i=(b)-1;i>=(a);--i)
#define ll long long
#define lb(x) ((x)&(-x))
#define pii pair<int,int>
#define vi vector<int>
#define pb push_back
#define fi first
#define se second
#define de(x) cout<<x<<" x"<<endl
#define LCAFA rep(i,1,20)rep(j,1,n+1)fa[j][i]=fa[fa[j][i-1]][i-1]
using namespace std;
const int N=1e5+9;
const ll mod=998244353;
int a[N],num[32],vis[N]; 
int main(){
	int n;
	scanf("%d",&n);
	rep(i,0,n){
		scanf("%d",&a[i]);
		rep(j,0,30)if(a[i]&(1<<j))num[j]++; 
	}
	int pos;
	for(pos=29;pos>=0;--pos){
		if(num[pos]==1)break;
	}
	if(pos==-1){
		rep(i,0,n)printf("%d ",a[i]);
	}
	else{
		rep(i,0,n){
			if(a[i]&(1<<pos)){
				printf("%d ",a[i]);
				vis[i]=1;
				break;
			}
		}
		rep(i,0,n){
			if(!vis[i])printf("%d ",a[i]);
		}
	}
}