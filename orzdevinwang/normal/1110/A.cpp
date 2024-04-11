#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int>
#define sz(a) ((int) (a).size())
using namespace std;
const int N = 1e6 + 7; 
int b, k, a[N];
int main () {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> b >> k;
	L(i, 1, k) 
		cin >> a[i];
	if(b % 2 == 0) {
		if(a[k] & 1) 
			cout << "odd\n";
		else 
			cout << "even\n";
	}
		
	else {
		int r = 0;
		L(i, 1, k) r ^= a[i];
		if(r & 1) 
			cout << "odd\n";
		else
			cout << "even\n";
	}
	return 0;
}