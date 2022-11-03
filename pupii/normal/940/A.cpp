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
int a[101];
int main(){
	#ifdef xzz
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	#endif
	int n=gi(),d=gi();
	for(rg int i=1;i<=n;++i)a[i]=gi();
	sort(a+1,a+n+1);
	int l=1,r=1,ans=0;
	while(a[r+1]-a[l]<=d&&r!=n)++r;
	ans=n-(r-l+1);
	while(r!=n){
		++l;
		while(a[r+1]-a[l]<=d&&r!=n)++r;
		ans=min(ans,n-(r-l+1));
	}
	printf("%d\n",ans);
	return 0;
}