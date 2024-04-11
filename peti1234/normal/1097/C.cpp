#include <bits/stdc++.h>

using namespace std;
int n, ans;
string s;
map<int, int> m;
int main()
{
    cin >> n;
    while (n--) {
        cin >> s;
        int maxi=0, mini=0, cnt=0;
        for (auto x:s) {
            cnt+=(x=='(' ? 1 : -1);
            maxi=max(maxi, cnt), mini=min(mini, cnt);
        }
        if (mini==0 || mini==cnt) {
            if (m[-cnt]) {
                m[-cnt]--;
                ans++;
            } else {
                m[cnt]++;
            }
        }
    }
    cout << ans << "\n";
    return 0;
}