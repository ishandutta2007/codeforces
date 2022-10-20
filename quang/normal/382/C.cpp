#include <bits/stdc++.h>
#define Task "C"
#define fi freopen(Task".inp", "r", stdin)
#define fo freopen(Task".out", "w", stdout)

using namespace std;

const int N = 100100;

int n;
int a[N];
pair <int, int> b[N];
vector <int > res;

void Inkq() {
    sort(res.begin(), res.end());
    int cnt = 0;
    for(int i = 0; i < res.size() ; i++) {
        if(i > 0 && res[i] == res[i - 1]) continue;
        cnt++;
    }
    cout << cnt << endl;
    for(int i = 0; i < res.size(); i++)  {
        if(i && res[i] == res[i - 1]) continue;
        cout << res[i] << " ";
    }
    exit(0);
}

int main() {
    ios_base::sync_with_stdio(0);
   // fi, fo;
    cin >> n;
    if(n == 1) {
        cout << -1;
        return 0;
    }
    for(int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    if(n == 2) {
        int kc = a[2] - a[1];
        res.push_back(a[1] - kc);
        res.push_back(a[2] + kc);
        if(kc % 2 == 0) res.push_back(a[1] + kc / 2);
        Inkq();
    }
    for(int i = 1; i < n; i++) b[i] = make_pair(a[i + 1] - a[i], i);
    sort(b + 1, b + n);
    for(int i = 2; i < n - 1; i++)
        if(b[i].first != b[1].first) {
            cout << 0;
            return 0;
        }
    if(b[n - 1].first == b[1].first) {
        res.push_back(a[1] - b[1].first);
        res.push_back(a[n] + b[1].first);
        Inkq();
    }
    if(b[n - 1].first == b[1].first * 2)  {
        int vt = b[n - 1].second;
        res.push_back(a[vt] + b[1].first);
        Inkq();
    }
    cout << 0;
    return 0;
}