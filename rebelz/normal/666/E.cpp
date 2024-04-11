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

struct node{
	int lch,rch;
	pii maxa;
}t[10000005];

int n,m,q,lst,cnt,ncnt;
int ch[1100005][26],fa[1100005],f[1100005][20],len[1100005],tmp[1100005],A[1100005],ed[500005],vs[1100005];
char s[500005],tt[50005];

void ins(int c){
	if(ch[lst][c]){
		int p=lst,q=ch[p][c];
		if(len[q]==len[p]+1) return (void)(lst=q);
		int nq=++cnt;
		len[nq]=len[p]+1;
		memcpy(ch[nq],ch[q],sizeof(ch[nq]));
		fa[nq]=fa[q],fa[q]=nq;
		for(;ch[p][c]==q;p=fa[p]) ch[p][c]=nq;
		lst=nq;
		return;
	}
	int p=lst,np=++cnt; lst=np,len[np]=len[p]+1;
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
	if(l==r){
		if(!t[id].maxa.fi) t[id].maxa=mp(1,-l);
		else t[id].maxa.fi++;
		return;
	}
	int mid=(l+r)/2;
	if(x<=mid) change(t[id].lch,l,mid,x);
	else change(t[id].rch,mid+1,r,x);
	t[id].maxa=max(t[t[id].lch].maxa,t[t[id].rch].maxa);
}

int merge(int x,int y,int l,int r){
	if(!x||!y) return x|y;
	if(l==r){
		int z=++ncnt;
		t[z].maxa.fi=t[x].maxa.fi+t[y].maxa.fi,t[z].maxa.se=-l;
		return z;
	}
	int mid=(l+r)/2,z=++ncnt;
	t[z].lch=merge(t[x].lch,t[y].lch,l,mid);
	t[z].rch=merge(t[x].rch,t[y].rch,mid+1,r);
	t[z].maxa=max(t[t[z].lch].maxa,t[t[z].rch].maxa);
	return z;
}

pii query(int id,int l,int r,int ql,int qr){
	if(!id) return mp(0,0);
	if(l==ql&&r==qr) return t[id].maxa;
	int mid=(l+r)/2;
	if(qr<=mid) return query(t[id].lch,l,mid,ql,qr);
	else if(ql>mid) return query(t[id].rch,mid+1,r,ql,qr);
	else return max(query(t[id].lch,l,mid,ql,mid),query(t[id].rch,mid+1,r,mid+1,qr));
}

int main(){
	scanf("%s",s+1); n=strlen(s+1);
	lst=cnt=1;
	for(int i=1;i<=n;i++) ins(s[i]-'a'),ed[i]=lst;
	m=readint();
	for(int i=1;i<=m;i++){
		scanf("%s",tt+1);
		lst=1;
		int l=strlen(tt+1);
		for(int j=1;j<=l;j++) ins(tt[j]-'a'),change(vs[lst],1,m,i);
	}
	for(int i=1;i<=cnt;i++) tmp[len[i]]++;
	for(int i=1;i<=cnt;i++) tmp[i]+=tmp[i-1];
	for(int i=cnt;i>=1;i--) A[tmp[len[i]]--]=i;
	for(int i=cnt;i>=1;i--) vs[fa[A[i]]]=merge(vs[fa[A[i]]],vs[A[i]],1,m),f[A[i]][0]=fa[A[i]];
	for(int i=1;i<=cnt;i++) for(int j=1;j<=19;j++) f[A[i]][j]=f[f[A[i]][j-1]][j-1];
	q=readint();
	int l1,r1,l2,r2;
	while(q--){
		l1=readint(); r1=readint(); l2=readint(); r2=readint();
		int now=ed[r2];
		for(int i=19;i>=0;i--) if(len[f[now][i]]>=r2-l2+1) now=f[now][i];
		pii tmp=query(vs[now],1,m,l1,r1);
		if(!tmp.se) printf("%d 0\n",l1);
		else printf("%d %d\n",-tmp.se,tmp.fi);
	}
	return 0;
}