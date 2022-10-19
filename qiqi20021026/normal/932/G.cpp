#include<bits/stdc++.h>

using namespace std;

#define N 1200000

const int mod=1000000007;
int n,fa[N],sf[N],len[N],f[N],g[N],diff[N],c[N][30],p,np,cnt;
char s[N],a[N];

void upd(int &x,int y){x=(x+y)%mod;}

int main(){
	scanf("%s",s+1); n=strlen(s+1);
	for (int i=1;i<=n/2;++i){
		a[i*2-1]=s[i];
		a[i*2]=s[n-i+1];
	}
	fa[0]=1; len[0]=0; fa[1]=1; len[1]=-1; np=cnt=1; f[0]=1;
	for (int i=1;i<=n;++i){
		int w=a[i]-'a';
		for (p=np;a[i]!=a[i-len[p]-1];p=fa[p]);
		if (!c[p][w]){
			int q=fa[p],now=++cnt; len[now]=len[p]+2;
			for (;a[i]!=a[i-len[q]-1];q=fa[q]);
			fa[now]=c[q][w];
			diff[now]=len[now]-len[fa[now]];
			c[p][w]=np=now;
			sf[now]=diff[now]==diff[fa[now]]?sf[fa[now]]:fa[now];
		}
		else np=c[p][w];
		for (int q=np;q;q=sf[q]){
			g[q]=f[i-len[sf[q]]-diff[q]];
			if (diff[q]==diff[fa[q]]) upd(g[q],g[fa[q]]);
			upd(f[i],g[q]);
		}
		if (i&1) f[i]=0;
	}
	printf("%d\n",f[n]);
	
	return 0;
}