#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	scanf("%i",&n);
	int arr[n];
	int li[n];
	for(int j = 0;j<n;j++){
		scanf("%i",&arr[j]);
		li[j] = arr[j];
	}
	for(int i = n-2;i>=0;i--){
		li[i] = min(li[i],li[i+1]);
	}
	int k = 0;
	int ans = 0;
	for(int i = 0;i<n;i++){
		if(k<=li[i])
			ans++;
		k = max(k,arr[i]);
	}
	printf("%i\n",ans);
	return 0;
}