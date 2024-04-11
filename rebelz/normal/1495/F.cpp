#include<bits/stdc++.h>

#define y1 dmytxdy
#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef long double ld;

template <typename T> bool chkmin(T &x,T y){return x>y?x=y,1:0;}
template <typename T> bool chkmax(T &x,T y){return x<y?x=y,1:0;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n,q,top;
ll p[200005],a[200005],b[200005],s[200005],fa[200005],ch[200005][2],rev[200005],sum[200005],val[200005],stk[200005],ans[200005];
vector<pii> qry[200005];

bool nroot(int x){return ch[fa[x]][0]==x||ch[fa[x]][1]==x;}
bool son(int x){return ch[fa[x]][1]==x;}
void reverse(int x){rev[x]^=1,swap(ch[x][0],ch[x][1]);}
void pushdown(int x){if(rev[x]) reverse(ch[x][0]),reverse(ch[x][1]),rev[x]=0;}
void update(int x){sum[x]=val[x]+sum[ch[x][0]]+sum[ch[x][1]];}

void rotate(int x){
	int y=fa[x],z=fa[y],k=son(x),w=ch[x][!k];
	if(nroot(y)) ch[z][son(y)]=x;
	ch[x][!k]=y,ch[y][k]=w;
	if(w) fa[w]=y;
	fa[y]=x,fa[x]=z;
	update(y),update(x);
}

void pushall(int x){
	if(nroot(x)) pushall(fa[x]);
	pushdown(x);
}

void splay(int x){
	pushall(x);
	while(nroot(x)){
		int y=fa[x];
		if(nroot(y)) rotate(son(x)==son(y)?y:x);
		rotate(x);
	}
}

void access(int x){for(int y=0;x;x=fa[y=x]) splay(x),ch[x][1]=y,update(x);}
void makeroot(int x){access(x); splay(x); reverse(x);}
void cut(int x,int y){makeroot(x); access(y); splay(x); assert(ch[x][1]==y); ch[x][1]=0,fa[y]=0; update(x);}

int main(){
	n=readint(); q=readint();
	for(int i=1;i<=n;i++) p[i]=readint();
	for(int i=1;i<=n;i++) a[i]=readint(),s[i]=s[i-1]+a[i];
	for(int i=1;i<=n;i++) b[i]=readint();
	set<int> st;
	st.insert(1),st.insert(n+1);
	qry[n+1].pb(mp(1,1));
	int x;
	for(int i=1;i<=q;i++){
		x=readint();
		if(x==1) continue;
		if(st.find(x)!=st.end()){
			st.erase(x);
			auto it2=st.lower_bound(x),it1=it2; it1--;
			qry[x].pb(mp(*it1,-i));
			qry[*it2].pb(mp(x,-i));
			qry[*it2].pb(mp(*it1,i));
		}
		else{
			auto it2=st.lower_bound(x),it1=it2; it1--;
			qry[x].pb(mp(*it1,i));
			qry[*it2].pb(mp(x,i));
			qry[*it2].pb(mp(*it1,-i));
			st.insert(x);
		}
	}
	top=0;
	p[n+1]=n+1;
	for(int i=1;i<=n+1;i++){
		if(top&&p[i-1]>p[i]){
			makeroot(i-1);
			val[i-1]=a[i-1];
			update(i-1);
			fa[i-1]=i;
			makeroot(i);
		}
		while(top&&p[stk[top]]<p[i]){
			if(stk[top]==i-1){
				makeroot(i-1);
				val[i-1]=min(a[i-1],b[i-1]);
				update(i-1);
				fa[i-1]=i;
				makeroot(i);
			}
			else{
				access(stk[top]); splay(stk[top]);
				if(sum[stk[top]]>b[stk[top]]){
					cut(stk[top],stk[top]+1);
					val[stk[top]]=b[stk[top]];
					update(stk[top]);
					fa[stk[top]]=i;
					makeroot(i);
				}
			}
			top--;
		}
		stk[++top]=i;
		for(auto j:qry[i]){
			access(j.fi); splay(j.fi);
			if(j.se>0) ans[j.se]+=sum[j.fi];
			else ans[-j.se]-=sum[j.fi];
		}
	}
	for(int i=1;i<=q;i++) ans[i]+=ans[i-1];
	for(int i=1;i<=q;i++) printf("%lld\n",ans[i]);
	return 0;
}