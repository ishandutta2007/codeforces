#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=2010;
int d[N],a[N];
int main(){
	int n,k;scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++)scanf("%d",a+i);
	if(k==n)return puts("0"),0;
	ll low=0,high=2012345678;
	while(low!=high){
		ll mid=(low+high)/2;
		for(int i=0;i<n;i++){
			d[i]=1;
			for(int j=i;j--;){
				if(abs(a[i]-a[j])<=abs(i-j)*mid)d[i]=max(d[i],d[j]+1);
			}
		}
		bool good=false;
		for(int i=0;i<n;i++){
			if(d[i]>=n-k){
				good=true;break;
			}
		}
		if(good)high=mid;
		else low=mid+1;
	}
	printf("%lld\n",low);
}