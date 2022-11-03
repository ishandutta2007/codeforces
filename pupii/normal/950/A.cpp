// It is made by XZZ
#include<cstdio>
#include<algorithm>
#define il inline
#define rg register
#define vd void
#define sta static
typedef long long ll;
il int gi(){
	rg int x=0,f=1;rg char ch=getchar();
	while(ch<'0'||ch>'9')f=ch=='-'?-1:f,ch=getchar();
	while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	return x*f;
}
int main(){
	#ifdef xzz
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	#endif
	int l=gi(),r=gi(),a=gi();
	while(a){
		if(l<r)++l;
		else ++r;
		--a;
	}
	printf("%d\n",std::min(l,r)*2);
	return 0;
}