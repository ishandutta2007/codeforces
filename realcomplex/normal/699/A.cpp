#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin >> n;
	char v[n];
	cin >> v;
	int col[n];
	int fir = INT_MAX;
	for(int j = 0;j<n;j++){
		cin >> col[j];
		if(j>0){
			if(v[j-1]=='R' && v[j]=='L'){
				fir = min(fir,(col[j]-col[j-1])/2);
			}
		}
	}
	cout << ((fir == INT_MAX) ? -1 : fir) << endl;
	return 0;
}