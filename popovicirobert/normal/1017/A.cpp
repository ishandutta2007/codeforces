#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44

using namespace std;

const int MAXN = 1000;

pair <int, int> arr[MAXN + 1];

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n;
    ios::sync_with_stdio(false);
    cin >> n;
    for(i = 1; i <= n; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        arr[i] = {a + b + c + d, i};
        arr[i].first *= -1;
    }
    sort(arr + 1, arr + n + 1);
    for(i = 1; i <= n; i++) {
        if(arr[i].second == 1) {
            cout << i;
            return 0;
        }
    }
    //cin.close();
    //cout.close();
    return 0;
}