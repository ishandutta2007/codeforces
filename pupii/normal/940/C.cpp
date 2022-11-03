// It is made by XZZ
#include<cstdio>
#include<algorithm>
#define il inline
#define rg register
#define vd void
#define sta static
typedef long long ll;
using namespace std;
il int gi(){
	rg int x=0,f=1;rg char ch=getchar();
	while(ch<'0'||ch>'9')f=ch=='-'?-1:f,ch=getchar();
	while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	return x*f;
}
int n,k,m;
char s[100001],S[100001],b[233];
int main(){
	#ifdef xzz
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	#endif
	n=gi(),k=gi();
	scanf("%s",s+1);
	for(rg int i=1;i<=n;++i)S[i]=s[i];
	sort(S+1,S+n+1);
	m=unique(S+1,S+n+1)-S-1;
	for(rg int i=1;i<=m;++i)b[S[i]]=i;
	if(k>n){
		printf("%s",s+1);
		for(rg int i=n+1;i<=k;++i)putchar(S[1]);
	}else{
		n=k;
		int i=n;
		while(s[i]==S[m])--i;
		s[i]=S[b[s[i]]+1];
		for(rg int j=i+1;j<=n;++j)s[j]=S[1];
		s[k+1]='\0';printf("%s",s+1);
	}
	return 0;
}