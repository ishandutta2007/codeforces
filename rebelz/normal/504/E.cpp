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

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

const int cys=1019260817,base=31;
int n,m,tot,ncnt;
int v[600005],nxt[600005],h[300005],dep[300005],siz[300005],dfn[300005],rnk[300005],f[300005],son[300005],top[300005];
ll pw[600005],hsh[600005];
char s[600005],str[300005];

ll mod(ll x){return x>=cys?x-cys:x;}
ll gethash(ll l,ll r){return mod(hsh[r]+cys-hsh[l-1]*pw[r-l+1]%cys);}

void addedge(int x,int y){
	v[++tot]=y; nxt[tot]=h[x]; h[x]=tot;
	v[++tot]=x; nxt[tot]=h[y]; h[y]=tot;
}

void dfs1(int u){
	siz[u]=1;
	for(int p=h[u];p;p=nxt[p]){
		if(v[p]==f[u]) continue;
		f[v[p]]=u,dep[v[p]]=dep[u]+1;
		dfs1(v[p]);
		siz[u]+=siz[v[p]];
		if(siz[v[p]]>siz[son[u]]) son[u]=v[p];
	}
}

void dfs2(int u){
	dfn[u]=++ncnt,rnk[ncnt]=u;
	if(son[u]) top[son[u]]=top[u],dfs2(son[u]);
	for(int p=h[u];p;p=nxt[p]){
		if(v[p]==f[u]||v[p]==son[u]) continue;
		top[v[p]]=v[p];
		dfs2(v[p]);
	}
}

vector<pii> getans(int x,int y){
	vector<pii> now1(0),now2(0);
	while(top[x]!=top[y]){
		if(dep[top[x]]>dep[top[y]]){
			now1.push_back(mp(n+n-dfn[x]+1,n+n-dfn[top[x]]+1));
			x=f[top[x]];
		}
		else{
			now2.push_back(mp(dfn[top[y]],dfn[y]));
			y=f[top[y]];
		}
	}
	if(dep[x]>dep[y]) now1.push_back(mp(n+n-dfn[x]+1,n+n-dfn[y]+1));
	else now2.push_back(mp(dfn[x],dfn[y]));
	reverse(now2.begin(),now2.end());
	for(auto x:now2) now1.push_back(x);
	return now1;
}

int getpl(int l1,int r1,int l2,int r2){
	int l=1,r=r1-l1+1,ret=0;
	while(l<=r){
		int mid=(l+r)/2;
		if(gethash(l1,l1+mid-1)==gethash(l2,l2+mid-1)) ret=mid,l=mid+1;
		else r=mid-1;
	}
	return ret;
}

int main(){
	n=readint();
	scanf("%s",str+1);
	pw[0]=1;
	for(int i=1;i<=n+n;i++) pw[i]=pw[i-1]*base%cys;
	for(int i=1;i<n;i++) addedge(readint(),readint());
	dep[1]=1; dfs1(1);
	top[1]=1; dfs2(1);
	for(int i=1;i<=n;i++) s[i]=str[rnk[i]];
	for(int i=n+1;i<=n+n;i++) s[i]=s[n+n-i+1];
	for(int i=1;i<=n+n;i++) hsh[i]=(hsh[i-1]*base+s[i]-'a')%cys;
	m=readint();
	int x1,y1,x2,y2;
	vector<pii> a1(0),a2(0);
	while(m--){
		x1=readint(); y1=readint(); x2=readint(); y2=readint();
		a1=getans(x1,y1),a2=getans(x2,y2);
		auto it1=a1.begin(),it2=a2.begin();
		int pl1=it1->fi-1,pl2=it2->fi-1,ans=0;
		while(it1!=a1.end()&&it2!=a2.end()){
			if(it1->se-pl1>it2->se-pl2){
				if(gethash(pl1+1,pl1+it2->se-pl2)!=gethash(pl2+1,it2->se)){
					ans+=getpl(pl1+1,pl1+it2->se-pl2,pl2+1,it2->se);
					break;
				}
				else ans+=it2->se-pl2,pl1+=it2->se-pl2,pl2=it2->se;
			}
			else{
				if(gethash(pl1+1,it1->se)!=gethash(pl2+1,pl2+it1->se-pl1)){
					ans+=getpl(pl1+1,it1->se,pl2+1,pl2+it1->se-pl1);
					break;
				}
				else ans+=it1->se-pl1,pl2+=it1->se-pl1,pl1=it1->se;
			}
			if(pl1==it1->se) it1++,pl1=it1->fi-1;
			if(pl2==it2->se) it2++,pl2=it2->fi-1;
		}
		printf("%d\n",ans);
	}
	return 0;
}