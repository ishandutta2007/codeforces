#include<cstdio>
#include<algorithm>
using namespace std;
#define F(i,a,b) for(int i=(a);i<=(b);++i)
int n,q,ans=0;
int a[100001];
int main(){
	scanf("%d%d",&n,&q);
	F(i,1,n) scanf("%d",a+i);
	sort(a+1,a+n+1);
	F(i,1,n){
		int xx=a[i], kk=-1;
		F(j,i,n){
			if(a[j]-xx>q) break;
			kk=j;
		}
		ans=max(ans,kk-i+1);
	}
	printf("%d",n-ans);
	return 0;
}