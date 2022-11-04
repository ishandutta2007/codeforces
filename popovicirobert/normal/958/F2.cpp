#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44

using namespace std;

const int MAXN = (int) 2e5;

int v[MAXN + 1];
int k[MAXN + 1];
int fr[MAXN + 1];

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n, m;
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for(i = 1; i <= n; i++) {
        cin >> v[i];
    }
    int s = 0, nr0 = 0;
    for(i = 1; i <= m; i++) {
        cin >> k[i];
        s += k[i];
        if(k[i] == 0)
            nr0++;
    }
    m -= nr0;
    int pos = 1, ans = MAXN + 1;
    int cnt = 0;
    for(i = 1; i <= n; i++) {
        if(pos < i)
            pos++;
        while(pos <= n && cnt < m) {
            fr[v[pos]]++;
            if(fr[v[pos]] == k[v[pos]])
                cnt++;
            pos++;
        }
        if(cnt == m) {
            ans = min(ans, pos - i - s);
            //printf("%d %d\n" ,i,pos);
        }
        fr[v[i]]--;
        if(fr[v[i]] == k[v[i]] - 1)
            cnt--;
    }
    if(ans == MAXN + 1)
        ans = -1;
    cout << ans;
    //cin.close();
    //cout.close();
    return 0;
}