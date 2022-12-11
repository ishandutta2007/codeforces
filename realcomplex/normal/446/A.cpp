#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5+5;
int arr[MAXN];
int l[MAXN];
void ini(){
	for(int j = 1;j<MAXN;j++)arr[j] = INT_MAX;
}
int main(){
	ini();
	int n;
	cin >> n;
	for(int j = 1;j<=n;j++){
		cin >> arr[j];
		if(arr[j]>arr[j-1])l[j]=l[j-1]+1;
		else l[j] = 1;
	}
	int ans = 1;
	int tek = 0;
	for(int j = n;j>0;j--){
		ans = max(ans,l[j-1]+1);
		ans = max(ans,tek+1);
		if(j == 1 || j == n || arr[j-1]+1<arr[j+1]) ans = max(ans,l[j-1]+1+tek);
		if(arr[j]<arr[j+1])tek++;
		else tek = 1;
	}
	cout << ans;
	return 0;
}