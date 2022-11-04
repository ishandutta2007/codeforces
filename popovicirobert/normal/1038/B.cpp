#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44

using namespace std;



int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, j, n;
    ios::sync_with_stdio(false);
    cin >> n;
    if(n <= 2) {
        cout << "No";
        return 0;
    }
    int len;
    if(n % 2 == 0) {
        len = n / 2;
    }
    if((n + 1) % 2 == 0) {
        len = (n + 1) / 2;
    }
    cout << "Yes" << "\n";
    cout << 1 << " " << len << "\n";
    cout << n - 1 << " ";
    for(i = 1; i <= n; i++) {
        if(i != len)
            cout << i << " ";
    }
    //cin.close();
    //cout.close();
    return 0;
}