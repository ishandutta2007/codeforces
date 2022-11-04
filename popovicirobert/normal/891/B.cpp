#include <bits/stdc++.h>
#define lsb(x)
#define ll long long

using namespace std;

const int MAXN = 22;

int a[MAXN + 1];

pair <int, int> b[MAXN + 1];

int ans[MAXN + 1];

int main(){
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n;
    ios::sync_with_stdio(false);
    cin >> n;
    for(i = 0; i < n; i++) {
        cin >> a[i];
        b[i] = {a[i], i};
    }
    sort(b, b + n);
    for(i = 0; i < n; i++) {
        ans[b[i].second] = b[(i + 1) % n].first;
    }
    for(i = 0; i < n; i++)
        cout << ans[i] << " ";
    //cin.close();
    //cout.close();
    return 0;
}