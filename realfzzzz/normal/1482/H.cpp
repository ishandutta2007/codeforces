#include<bits/stdc++.h>
using namespace std;
inline int readint(){
	int x=0;
	bool f=0;
	char c=getchar();
	while(!isdigit(c)&&c!='-') c=getchar();
	if(c=='-'){
		f=1;
		c=getchar();
	}
	while(isdigit(c)){
		x=x*10+c-'0';
		c=getchar();
	}
	return f?-x:x;
}
const int maxn=1e6+5,maxk=20;
int n,m,k,ord[maxk+1],s[maxn],t[maxn];
char buf[maxk+5];
int f[(1<<maxk)+5],g[(1<<maxk)+5],cnt[(1<<maxk)+5];
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	n=readint();
	m=readint();
	k=readint();
	scanf("%s",buf);
	for(int i=0;i<k;i++) s[0]|=(buf[i]-'0')<<i;
	scanf("%s",buf);
	for(int i=0;i<k;i++) t[0]|=(buf[i]-'0')<<i;
	for(int i=0;i<k;i++) ord[i]=i;
	for(int i=1;i<=n;i++){
		int a,b;
		a=readint()-1;
		b=readint()-1;
		swap(ord[a],ord[b]);
		for(int j=0;j<k;j++) s[i]|=(s[0]>>j&1)<<ord[j];
		for(int j=0;j<k;j++) t[i]|=(t[0]>>j&1)<<ord[j];
	}
	for(int i=0;i<(1<<k);i++){
		f[i]=n+1;
		g[i]=-1;
	}
	for(int i=0;i<=n;i++){
		f[s[i]]=min(f[s[i]],i);
		g[t[i]]=max(g[t[i]],i);
	}
	for(int i=(1<<k)-1;i>=0;i--) for(int j=0;j<k;j++){
		f[i]=min(f[i],f[1<<j|i]);
		g[i]=max(g[i],g[1<<j|i]);
	}
	for(int i=1;i<(1<<k);i++) cnt[i]=cnt[i>>1]+(i&1);
	int res=0;
	for(int i=1;i<(1<<k);i++) if(g[i]-f[i]>=m&&cnt[i]>cnt[res]) res=i;
	printf("%d\n%d %d\n",cnt[res]*2+k-cnt[s[0]]-cnt[t[0]],f[res]+1,g[res]);
	return 0;
}