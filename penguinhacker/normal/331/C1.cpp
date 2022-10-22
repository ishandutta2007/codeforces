#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	int n;
	cin >> n;
	
    int count = 0;
    while (n>0) {
        int best = 0;
        int s = n;
        while (s>0) {
            best = max(best, s%10);
            s /= 10;
        }
        n -= best;
        count++;
    }
	
    cout << count << '\n';
	return 0;
}