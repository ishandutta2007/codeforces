#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 220
// 44

using namespace std;

const int MAXN = (int) 1e5;

int first[MAXN + 1], last[MAXN + 1];

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n;
    ios::sync_with_stdio(false);
    cin >> n;
    for(i = 1; i <= MAXN; i++) {
        first[i] = MAXN + 1;
    }
    for(i = 1; i <= n; i++) {
        int x;
        cin >> x;
        if(first[x] == MAXN + 1)
            first[x] = i;
        last[x] = i;
    }
    sort(last + 1, last + MAXN + 1);
    sort(first + 1, first + MAXN + 1);
    int pos = 1;
    ll ans = 0;
    for(i = 1; i <= MAXN; i++) {
        while(pos <= MAXN && first[pos] < last[i]) {
            pos++;
        }
        ans += pos - 1;
    }
    cout << ans;
    //cin.close();
    //cout.close();
    return 0;
}