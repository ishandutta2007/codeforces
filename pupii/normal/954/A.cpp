// It is made by XZZ
#include<cstdio>
#include<algorithm>
#include<cstring>
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
char ch[10000];
int main(){
	#ifdef xzz
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	#endif{
	int n=gi();
	scanf("%s",ch+1);
	char lst=ch[1];
	int ans=n;
	for(rg int i=2;i<=n;++i){
		if(lst!='D'&&lst!=ch[i])--ans,lst='D';
		else lst=ch[i];
	}
	printf("%d\n",ans);
	return 0;
}