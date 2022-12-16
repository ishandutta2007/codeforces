#include <stdio.h>
#include <algorithm>
#define MN 100
typedef long long LL;
int n;
struct data{LL a,d;}dt[MN+5];
bool cmp(data i,data j){return i.d==j.d?i.a<j.a:i.d>j.d;}
int getd(LL x){
	int r=0;
	while(x%3==0)x/=3,r++;
	return r;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&dt[i].a);
		dt[i].d=getd(dt[i].a);
	}
	std::sort(dt+1,dt+1+n,cmp);
	for(int i=1;i<=n;i++)
		printf("%lld ",dt[i].a);
}