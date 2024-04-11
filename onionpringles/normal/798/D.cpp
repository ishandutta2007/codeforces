#include <stdio.h>
#include <tuple>
#include <algorithm>
using namespace std;
typedef tuple<int,int,int> tii;
tii a[101010];
int main(){
	int n;scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%d",&get<0>(a[i]));
	for(int i=0;i<n;i++)scanf("%d",&get<1>(a[i]));
	for(int i=0;i<n;i++)get<2>(a[i])=i;
	sort(a,a+n,greater<tii>());
	if(n%2==0)n++;
	printf("%d\n",n/2+1);
	printf("%d ",get<2>(a[0])+1);
	for(int i=1;i<n;i+=2){
		if(get<1>(a[i])>get<1>(a[i+1]))printf("%d ",get<2>(a[i])+1);
		else printf("%d ",get<2>(a[i+1])+1);
	}
	puts("");
}