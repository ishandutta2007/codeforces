#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int main() {
	int n;
	cin >> n;
    
    int hun, twen, ten, fiv, one;
    hun = n/100; n%=100;
    twen = n/20; n%=20;
    ten = n/10; n%=10;
    fiv = n/5; n%=5;
    one = n;

    cout << hun + twen + ten + fiv + one << '\n';
	return 0;
}