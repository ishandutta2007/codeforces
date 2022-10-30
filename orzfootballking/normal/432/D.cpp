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
const int MAXN=1e5+5;
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
		int j=0,k=0;
		for(int i=1; i<=tot; h[rk[i++]]=k) {
			j=sa[rk[i]-1];
			if(k)k--;
			while(a[i+k]==a[j+k])k++;
		}
	}
}S;
int mi[100005];
int get(int x){
	int re=1e9;
	while(x)gmin(re,mi[x]),x-=x&-x;
	RE re;
}
void up(int x,int y){
	while(x<=100000)mi[x]=y,x+=x&-x;
}
int ans[100005];
signed main(){
//	ios::sync_with_stdio(0);
//	cin.tie(0);
	string s;
	cin>>s;
	int n=s.size();
	S.in(n,s);
	S.init();
	int t=S.rk[1];
	int mini=S.h[t];
	V<int> v;
	for(int i=t-1;i>=1;i--){
		int now=S.sa[i];
		if(mini==n-now+1)v.PB(n-S.sa[i]+1);
		gmin(mini,S.h[i]);
	} 
	mini=1e9;
	FOR(i,t+1,n){
		gmin(mini,S.h[i]);
		int now=S.sa[i];
		if(mini==n-now+1)v.PB(n-S.sa[i]+1);
	}
	sort(ALL(v));v.PB(1e9);
	FOR(i,1,100000)mi[i]=1e9;
	up(1,n+1);
	for(int i=n;i>=1;i--){
		if(*lwb(ALL(v),n-S.sa[i]+1)==n-S.sa[i]+1){
			int p=S.sa[i];
			ans[n-S.sa[i]+1]=get(n-S.sa[i]+1)-i;
		}
		up(S.h[i]+1,i);
	}
	v.pop_back();
	ans[n]=1;
	v.PB(n);
	cout<<v.size()<<'\n';
	for(auto u:v){
		cout<<u<<' '<<ans[u]<<'\n';
	}
	RE 0;
}