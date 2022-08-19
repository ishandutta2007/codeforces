#include<bits/stdc++.h>

#define mp make_pair
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

struct node{
	int ch[2],val;
}t[15000005];

int n,q,lst,cnt,ncnt,l;
int m[200005],db[200005],siz[400005],rg[400005],a[400005],len[400005],ch[400005][26],fa[400005],tmp[400005],rt[400005],ed[200005];
string s[200005];

void change(int &id,int l,int r,int x){
	if(!id) id=++ncnt;
	if(l==r) return (void)(t[id].val+=1);
	int mid=(l+r)/2;
	if(x<=mid) change(t[id].ch[0],l,mid,x);
	else change(t[id].ch[1],mid+1,r,x);
	t[id].val=t[t[id].ch[0]].val+t[t[id].ch[1]].val;
}

void insert(int c,int g){
	if(ch[lst][c]){
		int p=lst,q=ch[p][c];
		if(len[q]==len[p]+1){
			change(rt[q],1,l,g);
			return (void)(lst=q);
		}
		int nq=++cnt;
		len[nq]=len[p]+1;
		memcpy(ch[nq],ch[q],sizeof(ch[nq]));
		fa[nq]=fa[q],fa[q]=nq;
		for(;p&&ch[p][c]==q;p=fa[p]) ch[p][c]=nq;
		lst=nq;
		change(rt[nq],1,l,g);
		return;
	}
	int p=lst,np=++cnt; lst=np,siz[np]=1,len[np]=len[p]+1;
	change(rt[np],1,l,g);
	for(;p&&!ch[p][c];p=fa[p]) ch[p][c]=np;
	if(!p) return (void)(fa[np]=1);
	int q=ch[p][c];
	if(len[q]==len[p]+1) return (void)(fa[np]=q);
	int nq=++cnt;
	len[nq]=len[p]+1;
	memcpy(ch[nq],ch[q],sizeof(ch[nq]));
	fa[nq]=fa[q],fa[np]=fa[q]=nq;
	for(;ch[p][c]==q;p=fa[p]) ch[p][c]=nq;
}

int merge(int x,int y){
	if(!x||!y) return x+y;
	int id=++ncnt;
	t[id].ch[0]=merge(t[x].ch[0],t[y].ch[0]);
	t[id].ch[1]=merge(t[x].ch[1],t[y].ch[1]);
	t[id].val=t[t[id].ch[0]].val+t[t[id].ch[1]].val;
	return id;
}

int query(int id,int l,int r,int ql,int qr){
	if(ql>qr) return 0;
	if(!id) return 0;
	if(l==ql&&r==qr) return t[id].val;
	int mid=(l+r)/2;
	if(qr<=mid) return query(t[id].ch[0],l,mid,ql,qr);
	else if(ql>mid) return query(t[id].ch[1],mid+1,r,ql,qr);
	else return query(t[id].ch[0],l,mid,ql,mid)+query(t[id].ch[1],mid+1,r,mid+1,qr);
}

int getans(int id){
	int p=1;
	for(int i=0;i<m[id];i++) p=ch[p][s[id][i]-'a'];
	return p;
}

int main(){
	n=readint(); q=readint();
	lst=cnt=l=1;
	for(int i=1;i<=n;i++){
		cin>>s[i];
		m[i]=s[i].length();
		l+=m[i];
	}
	int nn=1;
	for(int i=1;i<=n;i++){
		lst=1;
		for(int j=0;j<m[i];j++) insert(s[i][j]-'a',++nn);
		ed[i]=nn;
	}
	for(int i=1;i<=n;i++) db[i]=getans(i);
	for(int i=1;i<=cnt;i++) if(rg[i]) change(rt[i],1,l,rg[i]);
	for(int i=1;i<=cnt;i++) tmp[len[i]]++;
	for(int i=1;i<=cnt;i++) tmp[i]+=tmp[i-1];
	for(int i=cnt;i>=1;i--) a[tmp[len[i]]--]=i;
	for(int i=cnt;i>=2;i--) rt[fa[a[i]]]=merge(rt[fa[a[i]]],rt[a[i]]);
	int x,y,z;
	ed[0]=1;
	while(q--){
		x=readint(); y=readint(); z=readint();
		printf("%d\n",query(rt[db[z]],1,l,ed[x-1]+m[z],ed[y]));
	}
	return 0;
}