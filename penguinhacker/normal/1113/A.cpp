#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int main() {
	int n, v;
	cin >> n >> v;
	
    if (v >= n-1) {
        cout << n-1 << '\n';
        return 0;
    }

    int cost = v + ((n-v)*(n-v+1)/2 - 1);
    cout << cost << '\n';
	return 0;
}