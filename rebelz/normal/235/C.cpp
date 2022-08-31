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
char s[1000005],t[2000005];
int ch[2000005][26],len[2000005],siz[2000005],fa[2000005],tmp[2000005],A[2000005];
bool vis[2000005];
vector<int> gar;

void ins(int c){
	int p=lst,np=++cnt; lst=cnt,len[np]=len[p]+1,siz[np]=1;
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

int main(){
	scanf("%s",s+1); n=strlen(s+1);
	lst=cnt=1;
	for(int i=1;i<=n;i++) ins(s[i]-'a');
	for(int i=1;i<=cnt;i++) tmp[len[i]]++;
	for(int i=1;i<=n;i++) tmp[i]+=tmp[i-1];
	for(int i=cnt;i>=1;i--) A[tmp[len[i]]--]=i;
	for(int i=cnt;i>=1;i--) siz[fa[A[i]]]+=siz[A[i]];
	m=readint();
	for(int i=1;i<=m;i++){
		scanf("%s",t+1);
		int l=strlen(t+1),p=1,nowl=0; ll ans=0;
		for(int j=1;j<l;j++) t[j+l]=t[j];
		for(int j=1;j<=l+l-1;j++){
			while(p>1&&!ch[p][t[j]-'a']) p=fa[p],nowl=len[p];
			if(ch[p][t[j]-'a']) p=ch[p][t[j]-'a'],nowl++;
			while(len[fa[p]]>=l) nowl=len[fa[p]],p=fa[p];
//			cout<<"test "<<p<<' '<<nowl<<' '<<siz[p]<<endl;
			if(vis[p]) continue;
			if(nowl>=l){
				vis[p]=1,gar.pb(p);
				ans+=siz[p];
			}
		}
		for(auto x:gar) vis[x]=0;
		gar.clear();
		printf("%lld\n",ans);
	}
	return 0;
}