#include<cstdio>
#include<algorithm>
#include<cstring>
#define F(i,a,b) for(int i=a;i<=b;++i)
#define F2(i,a,b) for(int i=a;i<b;++i)
int k,n,m,a[100001],num[100001];
void init(){
	scanf("%d%d%d",&n,&k,&m);
	F(i,1,n) scanf("%d",a+i), ++num[a[i]%m];
}
int main(){
	init();
	F2(i,0,m) if(num[i]>=k){
		puts("Yes");
		F(j,1,n){
			if(a[j]%m==i){
				printf("%d ",a[j]);
				if((--k)==0) return 0;
			}
		}
	}puts("No");
	return 0;
}