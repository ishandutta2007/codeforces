// It is made by XZZ
#include<cstdio>
#include<algorithm>
#define il inline
#define rg register
#define vd void
#define sta static
#define int long long
using namespace std;
il int gi(){
	rg int x=0,f=1;rg char ch=getchar();
	while(ch<'0'||ch>'9')f=ch=='-'?-1:f,ch=getchar();
	while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	return x*f;
}
int st[17][100001];
int log[100001];
int f[100001];
main(){
	#ifdef xzz
	freopen("e.in","r",stdin);
	freopen("e.out","w",stdout);
	#endif
	int n=gi(),c=gi(),sum=0;
	for(rg int i=1;i<=n;++i)st[0][i]=gi(),sum+=st[0][i];
    for(rg int i=2;i<=n;++i)
        if(1<<log[i-1]+1==i)log[i]=log[i-1]+1;
        else log[i]=log[i-1];
    int Log=log[n];
    for(rg int i=1;i<=Log;++i)
        for(rg int j=n-(1<<i)+1;j;--j)
            st[i][j]=min(st[i-1][j],st[i-1][j+(1<<(i-1))]);
	int lg=log[c];
	for(rg int i=c;i<=n;++i)f[i]=max(f[i-1],f[i-c]+min(st[lg][i-c+1],st[lg][i-(1<<lg)+1]));
	printf("%I64d\n",sum-f[n]);
	return 0;
}