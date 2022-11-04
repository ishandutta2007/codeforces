#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
// 175
// 44

using namespace std;

const int MAXN = (int) 1e5;

string str[MAXN + 1];
int frs[MAXN + 1], frh[MAXN + 1];

int ord[MAXN + 1];

bool cmp(int a, int b) {
    return 1LL * frs[a] * frh[b] > 1LL * frs[b] * frh[a];
}

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int n, i;
    ios::sync_with_stdio(false);
    cin >> n;
    for(i = 1; i <= n; i++) {
        cin >> str[i];
        for(auto it : str[i]) {
            if(it == 's')
                frs[i]++;
            else
                frh[i]++;
        }
        ord[i] = i;
    }
    sort(ord + 1, ord + n + 1, cmp);
    ll ans = 0;
    int cnt = 0;
    for(i = 1; i <= n; i++) {
        for(auto it : str[ord[i]]) {
            if(it == 'h')
                ans += cnt;
            else
                cnt++;
        }
    }
    cout << ans;
    //cin.close();
    //cout.close();
    return 0;
}