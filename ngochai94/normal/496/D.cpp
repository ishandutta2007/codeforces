#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i = a; i <= b; i++)
#define FORD(i,a,b) for (int i = a; i >= b; i--)
#define REP(i,a) for (int i = 0; i < a; i++)
#define reset(a,b) memset(a,b,sizeof(a))
#define BUG(x) cout << #x << " = " << x << endl
#define mod 1000000007
#define eps 0.00000001
#define sqr(x) (x) * (x)
#define pb push_back

int n, lis[100005], cnt1[100005], cnt2[100005], where1[100005], where2[100005];
vector<pair<int, int> > ans;

int main() {
    ios::sync_with_stdio(0);
    cin >> n;
    reset(where1, 55);
    reset(where2, 55);
    FOR (i, 1, n) {
        cin >> lis[i];
        if (lis[i] == 1) {
            cnt1[i] = cnt1[i - 1] + 1;
            where1[cnt1[i]] = i;
            cnt2[i] = cnt2[i - 1];
        } else {
            cnt2[i] = cnt2[i - 1] + 1;
            where2[cnt2[i]] = i;
            cnt1[i] = cnt1[i - 1];
        }
    }
    // BUG(cnt1[n]);
    FOR (match, 1, max(cnt1[n], cnt2[n])) {
        // BUG(match);
        int win1 = 0, win2 = 0;
        bool flag = false;
        int lat = 0;
        while (lat < n) {
            int tmp1 = cnt1[n] - cnt1[lat];
            int tmp2 = cnt2[n] - cnt2[lat];
            if (tmp1 < match && tmp2 < match) {
                flag = true;
                break;
            }
            tmp1 = where1[cnt1[lat] + match];
            tmp2 = where2[cnt2[lat] + match];
            if (tmp1 < tmp2) {
                win1++;
                if (win1 > win2) flag = false;
                else flag = true;
                lat = tmp1;
            } else {
                win2++;
                if (win2 > win1) flag = false;
                else flag = true;
                lat = tmp2;
            }
        }
        if (!flag) {
            ans.pb({max(win1, win2), match});
        }
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for (auto p: ans) cout << p.first << ' ' << p.second << endl;
}