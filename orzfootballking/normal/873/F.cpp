#pragma GCC optimize("Ofast")
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
const int MAXN=2e5+5;
struct SA {
	int tot;
	int a[MAXN],h[MAXN],tax[MAXN],tp[MAXN],sa[MAXN],rk[MAXN];
	void resolve() {
		FOR(i,1,max(130,tot))tax[i]=0;
		FOR(i,1,tot)tax[rk[i]]++;
		FOR(i,1,max(130,tot))tax[i]+=tax[i-1];
		for(int i=tot; i>=1; i--)sa[tax[rk[tp[i]]]--]=tp[i];
	}
	bool cmp(int x,int y,int w) {
		RE tp[x]==tp[y]&&tp[x+w]==tp[y+w];
	}
	void in(int len,string s){
		rep(i,0,len)a[i+1]=s[i];
		tot=len;
	}
	void init() {
		FOR(i,1,tot)rk[i]=a[i],tp[i]=i;
		int p;
		resolve();
		for(int t=1; t<=tot; t+=t) {
			p=0;
			FOR(i,tot-t+1,tot)tp[++p]=i;
			FOR(i,1,tot)if(sa[i]>t)tp[++p]=sa[i]-t;
			resolve();
			swap(rk,tp);
			rk[sa[1]]=p=1;
			FOR(i,2,tot)rk[sa[i]]=cmp(sa[i],sa[i-1],t)?p:++p;
		}
		int j,k=0;
		for(int i=1; i<=tot; h[rk[i++]]=k) {
			j=sa[rk[i]-1];
			if(k)k--;
			while(a[i+k]==a[j+k])k++;
		}
	}
}S;
int p[MAXN],n,ps[MAXN]; 
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	string s;char c;
	cin>>n>>s;
	FOR(i,1,n){
		cin>>c;
		p[i]=c-'0';
		p[i]^=1;
	}
	reverse(ALL(s));
	S.in(n,s);S.init();
	reverse(p+1,p+n+1);
	set<P<int,int>> se;
	ll ans=0;
	FOR(i,1,n){
		ps[i]=ps[i-1]+p[S.sa[i]];
		auto iter=se.lwb(MP(S.h[i],0));
		int mini=1e9;
		while(iter!=se.end()){
			gmax(ans,1ll*(ps[i-1]-ps[(*iter).S-1])*(*iter).F);
			se.erase(iter);gmin(mini,(*iter).S);
			iter=se.lwb(MP(S.h[i],0));
		}
		if(mini<=n){
			se.insert(MP(S.h[i],mini));
		}
		se.insert(MP(n-S.sa[i]+1,i));
	}
	while(!se.empty()){
		auto iter=se.begin();
		gmax(ans,1ll*(ps[n]-ps[(*iter).S-1])*(*iter).F);
		se.erase(iter);
	}
	cout<<ans;
	RE 0;
}