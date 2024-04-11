#include <bits/stdc++.h>
#define fi freopen("inp.txt", "r", stdin)
#define fo freopen("out.txt", "w", stdout)
#define MAX
#define N 100010

using namespace std;

typedef pair<int, int> pi;

int n, m, s;
pi a[N], b[N];
int pass[N], id[N], res[N], res2[N];
bool flag = 0;

bool check(int day) {
    priority_queue < pi > q;
    int sum = 0, j = n;
    for(int i = m; i > 0; i -= day) {
        while(j && b[j].first >= a[i].first) {
            q.push( make_pair(-b[j].second, id[j]));
            j--;
        }
        if(q.empty()) return 0;
        int u = -q.top().first;
        int v = q.top().second;
        q.pop();
        if(flag) res[i] = v;
        sum += u;
        if(sum > s) return 0;
    }
    return sum <= s;
}

int main() {
    ios_base::sync_with_stdio(0);
   // fi, fo;
    cin >> n >> m >> s;
    for(int i = 1; i <= m; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a + 1, a + m + 1);
    for(int i = 1; i <= n; i++) {
        cin >> b[i].first;
        b[i].second = i;
    }
    for(int i = 1; i <= n; i++) cin >> pass[i];
    sort(b + 1, b + n + 1);
    for(int i = 1; i <= n; i++) {
        id[i] = b[i].second;
        b[i].second = pass[id[i]];
    }
    if(!check(m)) {
        cout << "NO";
        return 0;
    }
    int l = 1, r = m;
    while(l != r) {
        int mi = (l + r) >> 1;
        if(check(mi)) r = mi;
        else l = mi + 1;
    }
    flag = 1;
    check(l);
    for(int i = m - 1; i; i--) if(!res[i]) res[i] = res[i + 1];
    for(int i = 1; i <= m; i++) res2[a[i].second] = res[i];
    cout << "YES\n";
    for(int i = 1; i <= m; i++) cout << res2[i] << " ";
    return 0;
}