// It is made by XZZ
#include<cstdio>
#include<algorithm>
#include<set>
#include<queue>
#define int long long
#define il inline
#define rg register
#define vd void
#define sta static
using namespace std;
typedef long long ll;
il int gi(){
	rg int x=0,f=1;rg char ch=getchar();
	while(ch<'0'||ch>'9')f=ch=='-'?-1:f,ch=getchar();
	while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	return x*f;
}
int n,k,A,B,l,ans;
main(){
	#ifdef xzz
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	#endif
	n=gi(),k=gi(),A=gi(),B=gi();
	if(n==1){puts("0");return 0;}
	if(k==1)printf("%lld\n",A*(n-1));
	else{
		l=n,ans=0;
		while(l>=k){
			if(l%k)ans+=(l-l/k*k)*A,l=l/k*k;
			else ans+=min(A*(l-l/k),B),l=l/k;
		}
		printf("%lld\n",ans+(l-1)*A);
	}
	return 0;
}