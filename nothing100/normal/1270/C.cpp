#include<bits/stdc++.h>
#define LL long long
using namespace std;
int t,n,a[200010];
LL sum,xsum;
int main(){
	scanf("%d",&t);
	while (t--){
		scanf("%d",&n);
		for (int i=0;i<n;i++) scanf("%d",&a[i]);
		sum=xsum=0;
		for (int i=0;i<n;i++){
			sum=sum+a[i];
			xsum=xsum^a[i];
		}
		printf("2\n%lld %lld\n",xsum,xsum+sum);
	}
}