#include<bits/stdc++.h>
#define ll long long
#define gmax(x,y) x=max(x,y)
#define gmin(x,y) x=min(x,y)
#define F first
#define S second
#define P pair
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define V vector
#define RE return
#define ALL(a) a.begin(),a.end()
#define MP make_pair
#define PB emplace_back
#define PF emplace_front
#define FILL(a,b) memset(a,b,sizeof(a))
#define lwb lower_bound
#define upb upper_bound
using namespace std;
int n;
char c[1000005];
int p37[1000005],p[1000005],mod=998244353,ans[1000005];
int qry(int x,int y){
	RE (p[y]-1ll*p[x-1]*p37[y-x+1]%mod+mod)%mod;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	p37[0]=1;
	FOR(i,1,n){
		cin>>c[i];
		p37[i]=(p37[i-1]*37ll)%mod;
		p[i]=(p[i-1]*37ll+c[i]-'a')%mod;
	}
	int tl=n/2+1;
	for(int st=n/2;st>=1;st--){
		int len=st-tl+1;
		gmax(len,0);
		int ed=n-st+1;
//		cout<<len<<'\n';
		while(st-len>0&&qry(st-len,st+len)==qry(ed-len,ed+len)){
			ans[st-len]=2*len+1;
			len++;
		}
		gmin(tl,st-len+1);
	}
	FOR(i,1,(n+1)/2){
		if(!ans[i])cout<<-1<<' ';
		else cout<<ans[i]<<' ';
	}
	RE 0;
}