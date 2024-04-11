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
    int i, n;
    ios::sync_with_stdio(false);
    cin >> n;
    int sum = 0;
    for(i = 1; i <= n; i++) {
        int x;
        cin >> x;
        sum += abs(x);
    }
    cout << sum;
    //cin.close();
    //cout.close();
    return 0;
}