#include <iostream>
#include <algorithm>
using namespace std;
long long str[100000];
long long diff[100000];
long long prec[100000];
int main(){
	int n;
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> str[i];
	}
	sort(str, str+n);
	for(int i=0;i<n-1;i++){
		diff[i] = str[i+1] - str[i];
	}
	sort(diff, diff+n-1);
	prec[0] = 0;
	for(int i = 0; i<n-1;i++){
		prec[i+1] = prec[i] + diff[i];
	}
	int q;
	cin >> q;
	for(int i=0;i<q;i++){
		long long l, r;
		cin >> l >> r;
		int pos = upper_bound(diff, diff+n-1, r-l+1) - diff;
		cout << prec[pos] + (r - l + 1) * (n - pos) << endl;
	}
}