#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

const int cys=1000000007;
ll n,lst,cnt;
bool g[5005][5005];
ll s[5005],f[5005][5005],len[10005],siz[10005],rt[10005],ch[10005][2],fa[10005],l[5005],tmp[10005],aa[10005],ans[5005];

int ins(int c,int gg){
	int p=lst,np=++cnt; lst=np,len[np]=len[p]+1,siz[np]=1,rt[np]=gg;
	for(;p&&!ch[p][c];p=fa[p]) ch[p][c]=np;
	if(!p){
		fa[np]=1;
		return np;
	}
	int q=ch[p][c];
	if(len[q]==len[p]+1){
		fa[np]=q;
		return np;
	}
	int nq=++cnt;
	len[nq]=len[p]+1,rt[nq]=1<<30;
	memcpy(ch[nq],ch[q],sizeof(ch[nq]));
	fa[nq]=fa[q],fa[q]=fa[np]=nq;
	for(;ch[p][c]==q;p=fa[p]) ch[p][c]=nq;
	return np;
}

void go(int x,int gg){
	if(!x) return;//len[fa[x]]+1 ~ len[x]    rt[x]
	if(rt[x]!=gg) for(int i=gg-len[x]+1;i<=gg-len[fa[x]];i++) g[i][gg]=true;
	go(fa[x],gg);
}

bool calc(int l,int r){
	if(r-l+1!=4) return true;
	int tst=0;
	for(int i=l;i<=r;i++) tst=tst*2+s[i];
	return tst!=3&&tst!=5&&tst!=14&&tst!=15;
}

int main(){
	n=readint();
	for(int i=1;i<=n;i++) s[i]=readint();
	lst=cnt=1;
	for(int i=1;i<=n;i++) l[i]=ins(s[i],i);
	for(int i=1;i<=cnt;i++) tmp[len[i]]++;
	for(int i=1;i<=cnt;i++) tmp[i]+=tmp[i-1];
	for(int i=1;i<=cnt;i++) aa[tmp[len[i]]--]=i;
	for(int i=cnt;i>=1;i--) rt[fa[aa[i]]]=min(rt[fa[aa[i]]],rt[aa[i]]),siz[fa[aa[i]]]+=siz[aa[i]];
	for(int i=1;i<=n;i++) go(l[i],i);
	for(int i=1;i<=n;i++){
		f[i][i-1]=1;
		for(int j=i;j<=n;j++)
			for(int k=max(i-1,j-4);k<=j-1;k++)
				if(calc(k+1,j)) (f[i][j]+=f[i][k])%=cys;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++) if(!g[j][i]) (ans[i]+=f[j][i])%=cys;
	}
	for(int i=1;i<=n;i++) (ans[i]+=ans[i-1])%=cys;
	for(int i=1;i<=n;i++) printf("%d\n",ans[i]);
	return 0;
}