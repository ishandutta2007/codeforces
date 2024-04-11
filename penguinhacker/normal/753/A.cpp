#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int main() {
	int n;
	cin >> n;
	
    int MX = 1;
    for (int i=1; i<50; ++i) {
        if (i*(i+1)/2 > n) {
            MX = i-1;
            break;
        }
    }

    cout << MX << '\n';
    for (int i=1; i<=MX-1; ++i) {
        cout << i << ' ';
    }
    cout << n - MX*(MX-1)/2<< '\n';
	return 0;
}