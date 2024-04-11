#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int main() {
	int n;
	cin >> n;
    int a[100000];
	for (int i=0; i<n; ++i) cin >> a[i];

    int MX = 1; int current = 1;
    for (int i=1; i<n; ++i) {
        if (a[i] > a[i-1]) current++;
        else {
            MX = max(MX, current);
            current = 1;
        }
    }
    MX = max(MX, current);
    
    cout << MX << '\n';
	return 0;
}