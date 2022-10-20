#include <bits/stdc++.h>
#define Task "A"
#define fi freopen(Task".inp", "r", stdin)
#define fo freopen(Task".out", "w", stdout)

using namespace std;

int n;
vector <int> A[5];

int main() {
    ios_base::sync_with_stdio(0);
    //fi, fo;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        A[x].push_back(i);
    }
    int res = min(min(A[1].size(), A[2].size()), A[3].size());
    cout << res << endl;
    for(int i = 0; i < res; i++, cout << endl)
        for(int j = 1; j <= 3; j++) cout << A[j][i] << " ";
    return 0;
}