#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int A[100000];
int prec[100001];
int main(){
	int n;
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> A[i];
	}
	prec[0] = 0;
	for(int i=0;i<n;i++){
		prec[i+1] = prec[i] + A[i];
	}
	int q;
	cin >> q;
	for(int i=0;i<q;i++){
		int l, r;
		cin >> l >> r;
		int ans = prec[r] - prec[l-1];
		cout << ans / 10 << endl;
	}
	return 0;
}