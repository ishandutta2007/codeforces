#include <stdio.h>
#include <algorithm>
#include <vector>
#define MN 100000

using std::min;
using std::vector;

using ll = long long;

const ll INF = 1e18;

int n;
char s[MN+5],t[MN+5];

struct T_t{
	int T[MN*4+5];
	
	void init(int n){
		build(1,1,n);
	}
	
	void build(int k,int l,int r){
		T[k] = 0;
		if(l==r) return;
		int mid = (l+r)>>1;
		build(k<<1,l,mid);
		build(k<<1|1,mid+1,r);
	}
	
	void insert(int k,int l,int r,int p,int w){
		T[k] += w;
		if(l==r) return;
		int mid = (l+r)>>1;
		if(p<=mid) insert(k<<1,l,mid,p,w);
		else insert(k<<1|1,mid+1,r,p,w);
	}
	
	int query(int k,int l,int r,int L,int R){
		if(l==L&&r==R) return T[k];
		int mid = (l+r)>>1;
		if(R<=mid) return query(k<<1,l,mid,L,R);
		if(L>mid) return query(k<<1|1,mid+1,r,L,R);
		return query(k<<1,l,mid,L,mid)+query(k<<1|1,mid+1,r,mid+1,R);
	}
	
}T;

void init(){
	T.init(n);
}

int cmove(int l,int r){
	return r-l-T.query(1,1,n,l,r);
}

void remove(int p){
	s[p] = '#';
	T.insert(1,1,n,p,1);
}

void solve(){
	scanf("%d%s%s",&n,&s[1],&t[1]);
	init();
	vector<int> p[26];
	for(int i=n;i>=1;i--)
		p[s[i]-'a'].push_back(i);
	int ps = 1;
	ll ans = INF;
	ll pans = 0;
	for(int pt=1;pt<=n;pt++){
		while(s[ps]=='#') ps++;
		int tc = t[pt]-'a';
		for(int i=0;i<tc;i++){
			if(p[i].size()==0) continue;
			ans = min(ans,pans+cmove(ps,p[i].back()));
		}
		if(p[tc].size()==0) break;
		pans += cmove(ps,p[tc].back());
		remove(p[tc].back());
		p[tc].pop_back();
	}
	if(ans==INF)
		puts("-1");
	else
		printf("%lld\n",ans);
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--) solve();
}