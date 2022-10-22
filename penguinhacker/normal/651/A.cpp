#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int main() {
	int a, b;
	cin >> a >> b;

    int count = 0;
    while (true) {
        if (b > a) swap(a, b);
        if (b == 0) break;
        if (a == 1) break;
        b++;
        a -= 2;
        count++;
    }

    cout << count << '\n';
	return 0;
}