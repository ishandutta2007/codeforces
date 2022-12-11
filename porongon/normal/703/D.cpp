#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,to=b;i<to;++i)
using namespace std;

typedef long long ll;

int st[1<<22];

void upd(int k, int s, int e, int p, int v){
	if(s+1==e)st[k]=v;
	else {
		int m=(s+e)/2;
		if(p<m)upd(2*k,s,m,p,v);
		else upd(2*k+1,m,e,p,v);
		st[k]=st[2*k]^st[2*k+1];
	}
}

int query(int k, int s, int e, int a, int b){
	if(s>=b||e<=a)return 0;
	if(s>=a&&e<=b)return st[k];
	int m=(s+e)/2;
	return query(2*k,s,m,a,b)^query(2*k+1,m,e,a,b);
}

int n,q;
int x[1<<20];
map<int,int> p;
int a[1<<20];
int res[1<<20];
vector<pair<int,pair<int,int> > > w;

int main(){
	memset(a,-1,sizeof(a));
	scanf("%d",&n);
	fore(i,0,n){
		scanf("%d",x+i);
		if(p.find(x[i])!=p.end())a[i]=p[x[i]];
		p[x[i]]=i;
		w.pb(mp(i,mp(1<<20,0)));
	}
	scanf("%d",&q);
	fore(i,0,q){
		int l,r;
		scanf("%d%d",&l,&r);l--;
		w.pb(mp(r,mp(l,i)));
	}
	sort(w.begin(),w.end());
	fore(i,0,w.size()){
		if(w[i].snd.fst==(1<<20)){
			if(a[w[i].fst]>=0)upd(1,0,n,a[w[i].fst],x[w[i].fst]);
		}
		else {
			res[w[i].snd.snd]=query(1,0,n,w[i].snd.fst,w[i].fst);
		}
	}
	fore(i,0,q)printf("%d\n",res[i]);
	return 0;
}