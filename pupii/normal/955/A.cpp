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
main(){
	int H=gi(),M=gi();
	int h=gi(),d=gi(),c=gi(),n=gi();
	if(H<20)printf("%.4lf\n",
	min((h+n-1)/n*c*1.0,
	(h+(60*(19-H)+60-M)*d+n-1)/n*c*0.8
	));
	else printf("%.4lf\n",(h+n-1)/n*c*0.8);
    return 0;
}