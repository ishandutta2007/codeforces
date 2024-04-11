#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;
long long int arr[110000]={};
int main(){
	int n;
	int t1,t2;
	long long int ans=0;
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		scanf("%d %d",&t1,&t2);
		arr[t1]++;
		arr[t2]++;
	}
	for(int i=1;i<=n;i++){
		ans+=(arr[i]*(arr[i]-1))/(long long)(2);
	}
	cout<<ans;
}