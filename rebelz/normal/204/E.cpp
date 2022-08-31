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

int n,k,cnt,lst;
int ch[200005][26],len[200005],bef[200005],tmp[200005],a[200005],fa[200005],siz[200005],m[100005];
ll ans[200005];
char s[100005];
vector<int> c[100005];

void insert(int c){
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

void update(int x,int g){for(;x&&bef[x]!=g;x=fa[x]) siz[x]++,bef[x]=g;}

int main(){
	n=readint(); k=readint();
	lst=cnt=1;
	for(int i=1;i<=n;i++){
		lst=1;
		scanf("%s",s+1); m[i]=strlen(s+1);
		for(int j=1;j<=m[i];j++){
			insert(s[j]-'a');
			c[i].push_back(s[j]-'a');
		}
	}
	int now;
	for(int i=1;i<=n;i++){
		now=1;
		for(int j=1;j<=m[i];j++){
			now=ch[now][c[i][j-1]];
			update(now,i);
		}
	}
	for(int i=1;i<=cnt;i++) ans[i]=siz[i]<k?0:len[i]-len[fa[i]];
	for(int i=1;i<=cnt;i++) tmp[len[i]]++;
	for(int i=1;i<=cnt;i++) tmp[i]+=tmp[i-1];
	for(int i=cnt;i>=1;i--) a[tmp[len[i]]--]=i;
	for(int i=2;i<=cnt;i++) ans[a[i]]+=ans[fa[a[i]]];
	ll res;
	for(int i=1;i<=n;i++){
		now=1,res=0;
		for(int j=1;j<=m[i];j++){
			now=ch[now][c[i][j-1]];
			res+=ans[now];
		}
		printf("%lld ",res);
	}
	puts("");
	return 0;
}