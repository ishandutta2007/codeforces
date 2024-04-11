#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> marked(n+1);
    for (long long i = 2; i <= n; i++) {
        if (marked[i] == 0) {
            for (long long j = i*i; j <= n; j+=i) {
                marked[j] = 1;
            }
        }
    }
    
    for (int i = 4; i <= n; i++) {
        if (marked[i] == 1 and marked[n-i] == 1) {
            cout << i << " " << n-i;
            break;
        }
    }
    return 0;
}