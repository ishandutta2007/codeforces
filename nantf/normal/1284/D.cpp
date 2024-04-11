#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=222222;
#define MP make_pair
#define PB push_back
#define lson o<<1,l,mid
#define rson o<<1|1,mid+1,r
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define MEM(x,v) memset(x,v,sizeof(x))
inline ll read(){
	char ch=getchar();ll x=0,f=0;
	while(ch<'0' || ch>'9') f|=ch=='-',ch=getchar();
	while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
	return f?-x:x;
}
struct seg{
	int la,ra,lb,rb;
}s1[maxn],s2[maxn];
int n,la[maxn],ra[maxn],lb[maxn],rb[maxn],tmpa[maxn],tla,tmpb[maxn],tlb;
ll b1[maxn],b2[maxn];
inline bool cmpla(const seg &x,const seg &y){return x.la<y.la;}
inline bool cmpra(const seg &x,const seg &y){return x.ra<y.ra;}
inline bool cmplb(const seg &x,const seg &y){return x.lb<y.lb;}
inline bool cmprb(const seg &x,const seg &y){return x.rb<y.rb;}
inline void update(ll *bit,int p,ll v){
	for(int i=p;i<=max(tla,tlb);i+=i&-i) bit[i]+=v;
}
inline ll query(ll *bit,int p){
	ll s=0;
	for(int i=p;i;i-=i&-i) s+=bit[i];
	return s;
}
inline void update(int p,ll v){
	update(b1,p,v);
	update(b2,p,1ll*p*v);
}
inline ll query(int p){
	return 1ll*(p+1)*query(b1,p)-query(b2,p);
}
inline void update(int l,int r,ll v){
	update(l,v);update(r+1,-v);
}
inline ll query(int l,int r){
	return query(r)-query(l-1);
}
int main(){
	n=read();
	FOR(i,1,n){
		la[i]=read();ra[i]=read();lb[i]=read();rb[i]=read();
		tmpa[++tla]=la[i];tmpa[++tla]=ra[i];
		tmpb[++tlb]=lb[i];tmpb[++tlb]=rb[i];
	}
	sort(tmpa+1,tmpa+tla+1);tla=unique(tmpa+1,tmpa+tla+1)-tmpa-1;
	sort(tmpb+1,tmpb+tlb+1);tlb=unique(tmpb+1,tmpb+tlb+1)-tmpb-1;
	FOR(i,1,n){
		la[i]=lower_bound(tmpa+1,tmpa+tla+1,la[i])-tmpa;
		ra[i]=lower_bound(tmpa+1,tmpa+tla+1,ra[i])-tmpa;
		lb[i]=lower_bound(tmpb+1,tmpb+tlb+1,lb[i])-tmpb;
		rb[i]=lower_bound(tmpb+1,tmpb+tlb+1,rb[i])-tmpb; 
		s1[i]=s2[i]=(seg){la[i],ra[i],lb[i],rb[i]};
	}
	sort(s1+1,s1+n+1,cmpla);
	sort(s2+1,s2+n+1,cmpra);
	int cur=1;
	FOR(i,1,n){
		while(cur<=n && s2[cur].ra<s1[i].la){
			update(s2[cur].lb,s2[cur].rb,1);
			cur++;
		}
		if(query(s1[i].lb,s1[i].rb)) return puts("NO"),0;
	}
	MEM(b1,0);MEM(b2,0);
	sort(s1+1,s1+n+1,cmplb);
	sort(s2+1,s2+n+1,cmprb);
	cur=1;
	FOR(i,1,n){
		while(cur<=n && s2[cur].rb<s1[i].lb){
			update(s2[cur].la,s2[cur].ra,1);
			cur++;
		}
		if(query(s1[i].la,s1[i].ra)) return puts("NO"),0;
	}
	puts("YES");
}
//