#include<bits/stdc++.h>

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
	int val,lch,rch;
}t[30000005];

int n,lst,cnt,ncnt,ans;
int len[400005],siz[400005],fa[400005],ch[400005][26],f[400005][20],rt[400005],rg[400005],tmp[400005],A[400005],d[400005];
vector<int> adj[400005];
char s[200005];

void ins(int c){
	int p=lst,np=++cnt; lst=np,len[np]=len[p]+1,siz[np]=1;
	for(;p&&!ch[p][c];p=fa[p]) ch[p][c]=np;
	if(!p) return (void)(fa[np]=1);
	int q=ch[p][c];
	if(len[q]==len[p]+1) return (void)(fa[np]=q);
	int nq=++cnt;
	len[nq]=len[p]+1;
	memcpy(ch[nq],ch[q],sizeof(ch[nq]));
	fa[nq]=fa[q],fa[q]=fa[np]=nq;
	for(;ch[p][c]==q;p=fa[p]) ch[p][c]=nq;
}

void change(int &id,int l,int r,int x){
	if(!id) id=++ncnt;
	t[id].val++;
	if(l==r) return;
	int mid=(l+r)/2;
	if(x<=mid) change(t[id].lch,l,mid,x);
	else change(t[id].rch,mid+1,r,x);
}

int merge(int x,int y,int l,int r){
	if(!x||!y) return x+y;
	if(l==r){
		t[x].val+=t[y].val;
		return x;
	}
	int mid=(l+r)/2,ret=++ncnt;
	t[ret].val=t[x].val+t[y].val;
	t[ret].lch=merge(t[x].lch,t[y].lch,l,mid);
	t[ret].rch=merge(t[x].rch,t[y].rch,mid+1,r);
	return ret;
}

int query(int id,int l,int r,int ql,int qr){
	if(!id) return 0;
	if(l==ql&&r==qr) return t[id].val;
	int mid=(l+r)/2;
	if(qr<=mid) return query(t[id].lch,l,mid,ql,qr);
	else if(ql>mid) return query(t[id].rch,mid+1,r,ql,qr);
	else return query(t[id].lch,l,mid,ql,mid)+query(t[id].rch,mid+1,r,mid+1,qr);
}

void dfs(int u,int now,int top){
	ans=max(ans,now);
	for(auto v:adj[u]){
		if(query(rt[top],1,n,max(1,rg[v]-len[v]+len[top]),rg[v])>1) dfs(v,now+1,v);
		else dfs(v,now,top);
	}
}

int main(){
	n=readint();
	if(n==1) return printf("1\n"),0;
	scanf("%s",s+1);
	lst=cnt=1;
	for(int i=1;i<=n;i++) ins(s[i]-'a'),rg[lst]=i;
	int now=1;
	for(int i=1;i<=n;i++) now=ch[now][s[i]-'a'],change(rt[now],1,n,i);
	for(int i=1;i<=cnt;i++) tmp[len[i]]++;
	for(int i=1;i<=cnt;i++) tmp[i]+=tmp[i-1];
	for(int i=cnt;i>=1;i--) A[tmp[len[i]]--]=i;
	for(int i=cnt;i>=2;i--) rt[fa[A[i]]]=merge(rt[fa[A[i]]],rt[A[i]],1,n),siz[fa[A[i]]]+=siz[A[i]],rg[fa[A[i]]]=max(rg[fa[A[i]]],rg[A[i]]);
	for(int i=1;i<=cnt;i++) f[i][0]=fa[i];
	for(int i=1;i<=18;i++) for(int j=1;j<=cnt;j++) f[j][i]=f[f[j][i-1]][i-1];
//	for(int i=1;i<=cnt;i++) cout<<rt[i]<<' ';
//	cout<<endl;
	for(int i=2;i<=cnt;i++) adj[fa[i]].push_back(i);
	dfs(1,0,1);
	cout<<ans<<endl;
	return 0;
}