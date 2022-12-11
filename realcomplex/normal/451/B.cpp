
#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

int main(){
	int n;
	cin >> n;
	int sk[n];
	int ks[n];
	for(int j = 0;j<n;j++){
		cin >> sk[j];
		ks[j] = sk[j];
	}
	sort(sk,sk+n);
	int r = -1;
	int l = n;
	for(int j = 0;j<n;j++){
		if(sk[j] != ks[j]){
			l = min(l,j);
			r = max(r,j);
		}
	}
	if(r == -1){
		cout << "yes" << endl << "1 1" << endl;
		exit(0);
	}
	reverse(ks+l,ks+r+1);
	for(int j = 0;j<n;j++){
		if(ks[j]!=sk[j]){
			cout << "no" << endl;
			exit(0);
		}
	}
	cout << "yes" << endl;
	cout << l+1 << " " << r+1 << endl;
	return 0;
}