#include <bits/stdc++.h>

using namespace std;

const int l = 86400;

int main(){
	int n,t;
	cin >> n >> t;
	int k;
	for(int j = 1;j<=n;j++){
		cin >> k;
		k=l-k;
		if(t>k)t-=k;
		else{
			cout << j << endl;
			exit(0);
		}
	}
	return 0;
}