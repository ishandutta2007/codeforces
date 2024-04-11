#include <bits/stdc++.h>
#define MAXN 1000000

using namespace std;





int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int t, n;
    ios::sync_with_stdio(false);
    cin >> t;
    while(t > 0) {
        t--;
        cin >> n;
        long long sum = 0;
        for(long long p2 = 1; p2 <= n; p2 <<= 1)
            sum -= 2 * p2;
        cout << sum + (1LL * n * (n + 1)) / 2 << endl;
    }
    //cin.close();
    //cout.close();
    return 0;
}