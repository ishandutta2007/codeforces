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

int n,m,lst,cnt;
char a[500005],b[500005],s[1000005];
int fa[1000005],len[1000005],ch[1000005][26],slink[1000005],diff[1000005];
pii g[1000005],d[1000005];

void ins(int c,int l){
	int p=lst;
	for(;s[l-len[p]-1]!=s[l];p=fa[p]);
	if(!ch[p][c]){
		int q=++cnt,k=fa[p];
		len[q]=len[p]+2;
		for(;s[l-len[k]-1]!=s[l];k=fa[k]);
		fa[q]=ch[k][c],ch[p][c]=q;
		diff[q]=len[q]-len[fa[q]];
		if(diff[q]!=diff[fa[q]]) slink[q]=fa[q];
		else slink[q]=slink[fa[q]];
		g[q]=min(g[fa[q]],mp(d[l-len[q]].fi,l-len[q]));
	}
	lst=ch[p][c];
}

int main(){
	scanf("%s%s",a+1,b+1);
	m=strlen(a+1),n=m<<1;
	for(int i=1;i<=n;i++){
		if(i&1) s[i]=a[i/2+1];
		else s[i]=b[i/2];
	}
	lst=0,cnt=1,fa[0]=fa[1]=1,len[1]=-1,g[0]=g[1]=mp(1<<30,0);
	memset(d,0x3f,sizeof(d));
	d[0]=mp(0,0);
	for(int i=1;i<=n;i++){
		ins(s[i]-'a',i);
		int p=lst;
		for(;p>1;p=slink[p]){
			g[p]=mp(d[i-(len[slink[p]]+diff[p])].fi,i-(len[slink[p]]+diff[p]));
			if(diff[p]==diff[fa[p]]) chkmin(g[p],g[fa[p]]);
			if(i%2==0) chkmin(d[i],mp(g[p].fi+1,g[p].se));
		}
		if(i%2==0&&s[i]==s[i-1]) chkmin(d[i],mp(d[i-2].fi,i-2));
	}
	if(d[n].fi>m) return printf("-1\n"),0;
	printf("%d\n",d[n].fi);
	int now=n;
	while(now){
		if(d[now].se!=now-2) printf("%d %d\n",d[now].se/2+1,now/2);
		now=d[now].se;
	}
	return 0;
}