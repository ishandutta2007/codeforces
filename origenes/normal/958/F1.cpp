#include<iostream>
#include<cstring>
using namespace std;

const int N = 100 + 10;

int a[N], k[N], n, m;

int cnt[N];
bool check(int l, int r) {
    memset(cnt, 0, sizeof(cnt));
    for(int i = l; i <= r; i++) {
        cnt[a[i]]++;
    }

    for(int i = 1; i <= m; i++)
        if(cnt[i] != k[i]) return false;
    return true;
}

int main() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 1; i <= m; i++) cin >> k[i];

    for(int l = 0; l < n; l++)
        for(int r = l; r < n; r++)
            if(check(l, r)) {
                cout << "YES\n";
                return 0;
            }
    cout << "NO\n";
    return 0;
}