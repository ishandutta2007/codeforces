#include <bits/stdc++.h>
#define ll long long
#define lsb(x) (x & (-x))


using namespace std;

const int MAXN = (int) 1e5;

int p[MAXN + 1];
bool viz[MAXN + 1];

vector <int> v;

int main() {
    //fstream cin("A.in");
    //ofstream cout("A.out");
    int i, n;
    ios::sync_with_stdio(false);
    cin >> n;
    for(i = 1; i <= n; i++)
        cin >> p[i];
    for(i = 1; i <= n; i++) {
        if(viz[i] == 0) {
            int pos = i;
            int cnt = 0;
            while(viz[pos] == 0) {
                viz[pos] = 1;
                cnt++;
                pos = p[pos];
            }
            v.push_back(cnt);
        }
    }
    sort(v.begin(), v.end(), greater<int>());
    ll ans = 0;
    if(v.size() == 1)
        ans = 1LL * v[0] * v[0];
    else {
        ans = 1LL * (v[0] + v[1]) * (v[0] + v[1]);
        for(i = 2; i < v.size(); i++)
            ans += 1LL * v[i] * v[i];
    }
    cout << ans;
    //cin.close();
    //cout.close();
    return 0;
}