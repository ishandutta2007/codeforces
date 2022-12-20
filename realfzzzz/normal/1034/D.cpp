#include<bits/stdc++.h>
using namespace std;
using ll=long long;
inline ll read(){
	ll x=0;
	bool f=0;
	char c=getchar();
	while(!isdigit(c)){
		if(c=='-') f=1;
		c=getchar();
	}
	while(isdigit(c)){
		x=x*10+c-'0';
		c=getchar();
	}
	return f?-x:x;
}
const int maxn=3e5+5;
int n,k,a[maxn],b[maxn],ord[maxn*2],m;
struct seg{
	int l,r,v;
	bool operator <(const seg b)const{
		return r<b.r;
	}
};
set<seg> s;
auto split(int x){
	auto it=s.lower_bound({0,x,0});
	if(it==s.end()) return it;
	seg u=*it;
	s.erase(u);
	if(u.l<x) s.insert({u.l,x-1,u.v});
	return s.insert({x,u.r,u.v}).first;
}
vector<seg> q[maxn];
int c[maxn];
pair<ll,ll> calc(int k){
	ll s1=0,s2=0,s=0;
	int l=0,v=0;
	memset(c,0,sizeof(c));
	for(int i=1;i<=n;i++){
		for(seg x:q[i]){
			if(l>=x.l&&l<=x.r) v+=x.v;
			if(l>=x.l) s+=1ll*x.v*(min(x.r,l)-x.l+1);
			c[x.l]+=x.v;
			c[x.r+1]-=x.v;
		}
		while(l<i&&v+c[l+1]>=k) s+=v+=c[++l];
		s1+=l;
		s2+=s;
	}
	return {s1,s2};
}
int main(){
#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
#endif
	n=read();
	k=read();
	for(int i=1;i<=n;i++){
		ord[i]=a[i]=read();
		ord[n+i]=b[i]=read();
	}
	sort(ord+1,ord+n*2+1);
	m=unique(ord+1,ord+n*2+1)-ord-2;
	for(int i=1;i<=n;i++){
		a[i]=lower_bound(ord+1,ord+m+1,a[i])-ord;
		b[i]=lower_bound(ord+1,ord+m+1,b[i])-ord-1;
	}
	s.insert({1,m,0});
	for(int i=1;i<=n;i++){
		auto it2=split(b[i]+1),it1=split(a[i]);
		for(auto j=it1;j!=it2;j++)
			q[i].push_back({j->v+1,i,ord[j->r+1]-ord[j->l]});
		s.erase(it1,it2);
		s.insert({a[i],b[i],i});
	}
	int l=1,r=1e9;
	while(l<r){
		int mid=l+(r-l+1)/2;
		if(calc(mid).first>=k) l=mid;
		else r=mid-1;
	}
	auto res=calc(r);
	printf("%lld\n",res.second-r*(res.first-k));
#ifdef LOCAL
	fprintf(stderr,"%f\n",1.0*clock()/CLOCKS_PER_SEC);
#endif
	return 0;
}