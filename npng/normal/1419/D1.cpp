#include <cstdio>
#include <algorithm>
using namespace std;
const int Maxn=100000;
int n;
int a[Maxn+5];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+1+n);
	printf("%d\n",((n-1)>>1));
	for(int i=n,j=1;i>j;i--,j++){
		printf("%d %d ",a[i],a[j]);
	}
	if(n&1){
		printf("%d ",a[(n+1)>>1]);
	}
	puts("");
	return 0;
}