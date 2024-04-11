// It is made by XZZ
#include<bits/stdc++.h>
#define int long long
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
int E[100011];
main(){
	int n=gi(),U=gi();
	for(rg int i=1;i<=n;++i)E[i]=gi();
	double ans=0;
	int p=1;
	for(rg int i=1;i<=n;++i){
		while(E[p+1]-E[i]<=U&&p<n)++p;
		if(p>=i+2)ans=max(ans,(double)(E[p]-E[i+1])/(E[p]-E[i]));
	}
	if(ans==0)puts("-1");
	else printf("%.10lf\n",ans);
    return 0;
}