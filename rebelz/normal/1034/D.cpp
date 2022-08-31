#include<bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

bool chkmax(int &x,int y){return x<y?x=y,true:false;}
bool chkmin(int &x,int y){return x>y?x=y,true:false;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

struct node{
	int l,r,v;
	node(int _l=0,int _r=0,int _v=0):l(_l),r(_r),v(_v){}
	bool operator<(const node c)const{return l<c.l;}
};

typedef set<node>::iterator IT;
int n,m;
ll c[300005];
vector<pll> v[300005];
set<node> s;

IT split(int x){
	auto it=s.lower_bound(node(x,0,0));
	if(it!=s.end()&&it->l==x) return it;
	it--;
	int l=it->l,r=it->r,v=it->v;
	s.erase(it);
	s.insert(node(l,x-1,v));
	return s.insert(node(x,r,v)).fi;
}

pll getans(int k){
	ll s1=0,s2=0,t1=0,t2=0;
	memset(c,0,sizeof(c));
	for(int i=1,j=0;i<=n;i++){
		c[i]=0;
		for(auto x:v[i]){
			c[x.fi]-=x.se;
			if(x.fi<j) t1+=x.se*(j-x.fi),t2+=x.se;
			c[i]+=x.se;
		}
		while(j<=i&&t2-c[j]>=k) t2-=c[j],t1+=t2,j++;
		s1+=t1,s2+=j;
	}
	return mp(s1,s2);
}

int main(){
	n=readint(); m=readint();
	s.insert(node(1,1e9,0));
	int l,r;
	for(int i=1;i<=n;i++){
		l=readint(); r=readint();
		auto en=split(r),st=split(l);
		for(auto it=st;it!=en;it++) v[i].push_back(mp(it->v,it->r-it->l+1));
		s.erase(st,en);
		s.insert(node(l,r-1,i));
	}
	l=1,r=1e9; int ans=0;
	while(l<=r){
		int mid=(l+r)/2;
		if(getans(mid).se>=m) ans=mid,l=mid+1;
		else r=mid-1;
	}
	pll tmp=getans(ans);
	printf("%lld\n",tmp.fi-ans*(tmp.se-m));
	return 0;
}