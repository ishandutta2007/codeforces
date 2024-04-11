#include <iostream>
#include <cstring>
using namespace std;

const int N = 200000 + 10;

int n, m;
int a[N], b[N], cnt[N];

bool check(int u) {
    memset(cnt, 0, sizeof(cnt));
    int l = 1, r = l + u - 1;
    int tot = 0;
    for(int i = 1; i <= r; i++) {
        cnt[a[i]]++;
        if(cnt[a[i]] == b[a[i]]) tot++;
    }
    for(int i = 1; i <= m; i++)
        if(b[i] == 0) tot++;

    if(tot == m) return true;

    while(r < n) {
        if(cnt[a[l]] == b[a[l]]) tot--;
        cnt[a[l]]--; l++;
        r++;
        cnt[a[r]]++;
        if(cnt[a[r]] == b[a[r]]) tot++;
        if(tot == m) return true;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) { cin >> a[i]; cnt[a[i]]++; }
    for (int i = 1; i <= m; i++) cin >> b[i];

    for(int i = 1; i <= m; i++)
        if(cnt[i] < b[i]) {
            cout << -1 << '\n';
            return 0;
        }

    int l = 1, r = n + 1;
    while(l < r) {
        int mid = l + (r - l) / 2;
        if(check(mid)) r = mid;
        else l = mid + 1;
    }

    int tot = 0;
    for(int i = 1; i <= m; i++) tot += b[i];
    //cout << tot << endl;
    //cout << tot << ' ' << l << endl;
    cout << l - tot << '\n';
    return 0;
}