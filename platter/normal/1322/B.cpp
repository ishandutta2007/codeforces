#include <bits/stdc++.h>
using namespace std;

int n;
int arr[400000];
int temp[400000];

int solve(int bit) {
	for(int i=0;i<n;i++) {
		temp[i]=arr[i]%(1<<(bit+1));
	}
	sort(temp,temp+n);
	long long ret=0;
	for(int i=0;i<n;i++) {
		ret+=lower_bound(temp+i+1,temp+n,2*(1<<bit)-temp[i])-lower_bound(temp+i+1,temp+n,(1<<bit)-temp[i]);
		ret+=lower_bound(temp+i+1,temp+n,4*(1<<bit)-temp[i])-lower_bound(temp+i+1,temp+n,3*(1<<bit)-temp[i]);
	}
	return ret%2;
}

int main(void) {
	scanf("%d\n",&n);
	for(int i=0;i<n;i++) {
		scanf("%d ",&arr[i]);
	}
	int ret=0;
	for(int i=0;i<=24;i++) {
		ret+=solve(i)*(1<<i);
	}
	printf("%d",ret);
}