#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin >> n;
	int sk[n];
	for(int j = 0;j<n;j++)cin>>sk[j];
	sort(sk,sk+n);
	int l = 0,r = n-1;
	for(int j = 0;j<n;j++){
		if(j%2==0){
			cout << sk[l] << " ";
			l++;
		}
		else{
			cout << sk[r] << " ";
			r--;
		}
	}
	return 0;
}