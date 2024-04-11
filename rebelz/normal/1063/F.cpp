// xtqqwq
#include<bits/stdc++.h>

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

struct node{
	int l,r,pl;
	node(int l=0,int r=0,int pl=0):l(l),r(r),pl(pl){}
};

int n,lst,cnt;
int f[20][1000005],ch[1000005][26],len[1000005],fa[1000005],now[1000005],ls[1000005],ed[500005];
vector<int> adj[1000005];
vector<node> vec[1000005];
char s[500005];

void ins(int c){
	int p=lst,np=++cnt; lst=np,len[np]=len[p]+1;
	for(;p&&!ch[p][c];p=fa[p]) ch[p][c]=np;
	if(!p) return (void)(fa[np]=1);
	int q=ch[p][c];
	if(len[q]==len[p]+1) return (void)(fa[np]=q);
	int nq=++cnt;
	len[nq]=len[p]+1;
	fa[nq]=fa[q],fa[q]=fa[np]=nq;
	memcpy(ch[nq],ch[q],sizeof(ch[nq]));
	for(;ch[p][c]==q;p=fa[p]) ch[p][c]=nq;
}

int main(){
	n=readint();
	scanf("%s",s+1);
	reverse(s+1,s+n+1);
	lst=cnt=1;
	for(int i=1;i<=n;i++) ins(s[i]-'a'),ed[i]=lst;
	for(int i=2;i<=cnt;i++) adj[fa[i]].pb(i);
	for(int i=1;i<=cnt;i++) f[0][i]=fa[i];
	for(int i=1;i<20;i++) for(int j=1;j<=cnt;j++) f[i][j]=f[i-1][f[i-1][j]];
	for(int i=2;i<=cnt;i++) now[i]=len[fa[i]],ls[i]=n+1;
	now[0]=-1;
	vec[1].pb(node(0,0,0));
	for(int i=0;i<26;i++) if(ch[1][i]) vec[ch[1][i]].pb(node(1,1,0));
	int ans=0;
	for(int i=1;i<=n;i++){
		int u=ed[i];
		for(int j=19;j>=0;j--){
			int v=f[j][u];
			if(!(vec[v].size()&&vec[v][0].pl+vec[v][0].l<=i)&&ls[v]+now[v]+1>i&&now[v]<len[v]) u=v;
		}
		if(!(vec[u].size()&&vec[u][0].pl+vec[u][0].l<=i)&&ls[u]+now[u]+1>i&&now[u]<len[u]) u=f[0][u];
		if(now[u]==len[u]) continue;
		int mx=now[u];
		if(ls[u]+now[u]+1<=i) chkmax(mx,now[u]+1);
		if(vec[u].size()&&vec[u][0].pl+vec[u][0].l<=i){
			int L=0,R=vec[u].size()-1,res=0;
			while(L<=R){
				int mid=(L+R)/2;
				if(vec[u][mid].pl+vec[u][mid].l<=i) res=mid,L=mid+1;
				else R=mid-1;
			}
			chkmax(mx,min(vec[u][res].r,i-vec[u][res].pl));
		}
		if(now[u]==mx) continue;
		chkmax(ans,mx);
		vector<int> pts(0);
		for(int v=u;now[v]<mx&&now[v]<len[v];v=fa[v]) pts.pb(v);
		reverse(pts.begin(),pts.end());
		for(auto v:pts){
			for(int j=0;j<26;j++) if(ch[v][j]) vec[ch[v][j]].pb(node(now[v]+2,min(mx,len[v])+1,i));
			now[v]=min(mx,len[v]);
			if(now[v]==len[v]){
				for(auto r:adj[v]) if(now[r]==len[v]) chkmin(ls[r],i);
			}
		}
		if(mx==len[u]){
			for(auto v:adj[u]) ls[v]=i;
		}
		else ls[u]=i;
	}
	printf("%d\n",ans);
	return 0;
}