#include <bits/stdc++.h>
using namespace std;

int arr[100];

int diff(int a,int b) {
	return a>b?a-b:b-a;
}

int main(void) {
	int tc;
	scanf("%d\n",&tc);
	for(int t=0;t<tc;t++) {
		int n,m,k;
		scanf("%d %d %d\n",&n,&m,&k);
		for(int i=0;i<n;i++) {
			scanf("%d ",&arr[i]);
		}
		scanf("\n");
		bool flag=true;
		for(int i=0;i<n-1;i++) {
			if (arr[i]<arr[i+1]-k) {
				m-=arr[i+1]-k-arr[i];
			}
			else {
				m+=arr[i]-max(arr[i+1]-k,0);
			}
			if (m<0) {
				flag=false;
			}
		}
		printf("%s\n",flag?"YES":"NO");
	}
}