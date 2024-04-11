#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
vector<int> b;
vector<int> c;
vector<int> d;
int ans = 0;
bool check(int v,int next) {
    if (next == -1) return false;
    if (c[v] < next) return false;
    if (b[c[v]] == d[c[v]]) return false;
    b[c[v]]++;
    ans = max(ans,b[c[v]]);
    return true;
}
int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    b.resize(n + 1,0);
    d.resize(n + 1,n);
    for(int i = 0;i < n;i++) {
        int next;
        cin >> next;
        while (c.size() > 0 && !check(c.size() - 1,next)) c.erase(c.end() - 1);
        if (c.size() != 0) {
            d[next] = b[c[c.size() - 1]];
        }
        c.push_back(next);
    }
    cout << ans;
}