#include<cstdio>
#include<algorithm>
using namespace std;
int n,p,l,r;
int main(){
	scanf("%d%d%d%d",&n,&p,&l,&r);
	if(l==1&&r==n) printf("0");
	else if(l==1) printf("%d",abs(p-r)+1);
	else if(r==n) printf("%d",abs(p-l)+1);
	else if(p<l) printf("%d",r-p+2);
	else if(p>r) printf("%d",p-l+2);
	else if(p-l>r-p) printf("%d",r-p+r-l+2);
	else printf("%d",p-l+r-l+2);
	return 0;
}