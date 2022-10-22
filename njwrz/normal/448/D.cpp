#include<bits/stdc++.h>
using namespace std;
long long n,m,k; 
long long check(long long x){
	long long re=1,i;
	for(i=1;i<=n;i++)re+=min((x-1)/i,m);
	return re;
}
int main() {
	cin>>n>>m>>k;
	if(k==n*m){
		cout<<k;return 0;
	}
	long long l=1,r=n*m,mid,i;
	while(r-l>3){
		mid=(r+l)>>1;
		if(check(mid)<=k){
			l=mid+1;
		}else{
			r=mid;
		}
	}
	for(i=l-1;i<=r;i++){
		if(check(i+1)>k){
			cout<<i;return 0;
		}
	}
	return 0;
}