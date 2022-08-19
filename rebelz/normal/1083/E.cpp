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

template <typename T> bool chkmax(T &x,T y){return x<y?x=y,true:false;}
template <typename T> bool chkmin(T &x,T y){return x>y?x=y,true:false;}

namespace FastIO {
	#define SIZE 100000
	inline char nc(){
		#ifdef WIN32
			return getchar();
		#endif
		static char buf[SIZE],*p1=buf+SIZE,*p2=buf+SIZE;
		if(p1==p2) p2=(p1=buf)+fread(buf,1,SIZE,stdin);
		return p1==p2?-1:*p1++;
	}
	inline bool blank(char ch){return ch==' '||ch=='\n'||ch=='\r'||ch=='\t';}
	template <class T> inline void read(T &x){
		register double tmp = 1;
		register bool sign = 0;
		x = 0;
		register char ch=nc();
		for(;ch<'0'||ch>'9';ch=nc()) if(ch=='-') sign=1;
		for(;ch>='0'&&ch<='9';ch=nc()) x=x*10+ch-'0';
		if(ch=='.') for(ch=nc();ch>='0'&&ch<='9';ch=nc()) tmp/=10.0,x+=tmp*(ch-48);
		if(sign) x=-x;
	}
	inline void read(char *s){
		register char ch=nc();
		for (;blank(ch);ch=nc());
		for (;!blank(ch);ch=nc()) *s++=ch;
		*s=0;
	}
	inline void read(char &c){
		for(c=nc();blank(c);c=nc());
	}
	template <class T> inline void print(T x){
		if(x<0) putchar('-'),x=-x;
		if(x>9) print(x/10);
		putchar('0'+x%10);
	}
	template <class T> inline void print(T x,char c){
		print(x),putchar(c);
	}
}
using namespace FastIO;

struct node{
	ll x,y,val,id;
	bool operator<(const node c)const{return x>c.x;}
}a[1000005];

int n,cnt,ncnt; ll ans=0;
ll k[1000005],b[1000005],p[1000005];
int tag[3000005];

ll getv(int id,int x){return k[id]*x+b[id];}

void update(int id,int l,int r,int c){
	if(!tag[id]) return (void)(tag[id]=c);
	if(l==r){
		if(getv(c,p[l])>getv(tag[id],p[l])) tag[id]=c;
		return;
	}
	int mid=(l+r)/2;
	if(k[c]>k[tag[id]]){
		if(getv(c,p[mid])>getv(tag[id],p[mid])) update(id<<1,l,mid,tag[id]),tag[id]=c;
		else update(id<<1|1,mid+1,r,c);
	}
	else{
		if(getv(c,p[mid])>getv(tag[id],p[mid])) update(id<<1|1,mid+1,r,tag[id]),tag[id]=c;
		else update(id<<1,l,mid,c);
	}
}

ll query(int id,int l,int r,int x){
	if(!tag[id]) return 0;
	if(l==r) return getv(tag[id],p[x]);
	int mid=(l+r)/2;
	if(x<=mid) return max(getv(tag[id],p[x]),query(id<<1,l,mid,x));
	else return max(getv(tag[id],p[x]),query(id<<1|1,mid+1,r,x));
}

int main(){
	read(n);
	for(int i=1;i<=n;i++) read(a[i].x),p[i]=a[i].x,read(a[i].y),read(a[i].val),a[i].id=i;
	sort(p+1,p+n+1);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) a[i].x=lower_bound(p+1,p+n+1,a[i].x)-p;
	for(int i=1;i<=n;i++){
		ll tmp=max(0ll,query(1,1,n,a[i].x))+p[a[i].x]*a[i].y-a[i].val;
		k[++cnt]=-a[i].y,b[cnt]=tmp;
		update(1,1,n,cnt);
		chkmax(ans,tmp);
	}
	printf("%lld\n",ans);
	return 0;
}