#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define per(i,a,b) for(int i=(b);i>(a);--i)
#define vi vector<int>
#define pb push_back
using namespace std;
const int N=1e6+9;
const int mod=1e9+7;
vi g[N];
int mul[N],jie[N],num[N],num1[N],type[N],L[N],R[N];
int main(){
	jie[0]=1;
	rep(i,1,N)jie[i]=1ll*i*jie[i-1]%mod,mul[i]=1;
	int n;
	scanf("%d",&n);
	rep(i,2,n+1){
		if(!g[i].size()){
			num[n/i]++;type[i]=n/i;
			for(int j=i;j<=n;j+=i){
				g[j].pb(i);mul[j]*=i;
			}
		}
	}
	num[1]++,type[1]=1;
	rep(i,1,n+1)num1[mul[i]]++;
	g[1].pb(1);
	int ok=0;
	rep(i,1,n+1){
		int x;
		scanf("%d",&x);
		if(!x||ok)continue;
		num1[mul[x]]--;
		if(g[x].size()!=g[i].size())ok=1;
		rep(j,0,g[x].size()-1){
			if(g[x][j]!=g[i][j]){
				ok=1;
				break;
			}
		}
		int y=g[i].back();
		x=g[x].back();
		if(type[x]!=type[y])ok=1;
		if(L[x]&&L[x]!=y)ok=1;
		if(R[y]&&R[y]!=x)ok=1;
		if(!L[x]&&!R[y])--num[type[x]];
		L[x]=y,R[y]=x;
	}
	if(ok){
		puts("0");
		return 0;
	}
	int ans=1;
	rep(i,1,n+1)ans=1ll*ans*jie[num[i]]%mod*jie[num1[i]]%mod;
	cout<<ans;
}