#include<bits/stdc++.h>
#define int long long
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
#define PF push_front
#define FILL(a,b) memset(a,b,sizeof(a))
#define lwb lower_bound
#define upb upper_bound
#define lc (x<<1)
#define rc ((x<<1)|1)
#define sz(x) ((int)x.size())
using namespace std;
const int mod=998244353;
int s[100005],a[100005],s2[100005];
int n,pw[100005];
int f[300005],inv[300005],finv[300005];
void add(int &x,int y){
	x+=y;
	if(x>=mod)x-=mod;
}
int POW(int x,int y){
	int re=1;
	while(y){
		if(y&1)re=re*x%mod;
		x=x*x%mod;
		y/=2;
	}
	RE re;
}
int C(int x,int y){
	if(x<0||y<0||x<y)RE 0;
	RE f[x]*finv[y]%mod*finv[x-y]%mod;
}
void pref(){
	f[0]=f[1]=inv[1]=finv[0]=finv[1]=1;
	FOR(i,2,n){
		f[i]=f[i-1]*i%mod;
		inv[i]=mod-inv[mod%i]*(mod/i)%mod;
		finv[i]=finv[i-1]*inv[i]%mod;
	}
}
void solve(){
	cin>>n;
	pref();
	FOR(i,1,n)cin>>a[i],s[i]=s[i-1]+a[i];
	s2[n+1]=0;
	for(int i=n;i>=1;i--)s2[i]=s2[i+1]+a[i];
	int sum=1;
	int itl=0,itr=n+1;
	if(s[n]==0){
		cout<<pw[n-1]<<'\n';RE ;
	}
	while(itl<itr){
//		cout<<itl<<' '<<itr<<'\n';
		if(s[itl]==s2[itr]){
			int tol=itl,tor=itr;
			if(s[itr-1]==s[itl]){
				sum=sum*(pw[itr-itl])%mod;break;
			}
			while(s[tol+1]==s[itl])tol++;
			while(s2[tor-1]==s2[itr])tor--;
			int l1=tol-itl+1,l2=itr-tor+1;
			if(!itl)l1--,l2--;
			int mul=0;
			FOR(i,0,min(l1,l2)){
				add(mul,C(l1,i)*C(l2,i)%mod);
			}
			sum=sum*mul%mod;
			itl=tol+1,itr=tor-1;
		}else if(s[itl]<s2[itr])itl++;else itr--;
	}
	cout<<(sum+mod)%mod<<'\n';
}
signed main(){
	pw[0]=1;
	FOR(i,1,100000)pw[i]=pw[i-1]*2%mod;
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)solve(); 
	RE 0;
}