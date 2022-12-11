#include <bits/stdc++.h>

using namespace std;

int main(){
	int n,a;
	scanf("%i %i",&n,&a);
	int arr[n];
	for(int j = 0;j<n;j++)scanf("%i",&arr[j]);
	a--;
	int ans = arr[a];
	for(int j = 1;j<=n;j++){
		if(a-j>=0&&a+j<n)ans+=(arr[a-j]==1&&arr[a+j]==1)*2;
		else{
			if(a-j<0&&a+j<n){
				ans += arr[a+j];
			}
			if(a+j>=n&&a-j>=0)ans += arr[a-j];
		}
	}
	printf("%i\n",ans);
	return 0;
}