#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int w, n, m, k;
    cin >> w;
    while (w--) {
        cin >> n >> m >> k;
        string a, b;
        cin >> a >> b;
        sort(a.rbegin(), a.rend()), sort(b.rbegin(), b.rend());
        int cnt=0;
        string ans;
        while (a.size()>0 && b.size()>0) {
            if (cnt==k) {
                ans.push_back(b.back());
                b.pop_back();
                cnt=-1;
            } else if (cnt==-k) {
                ans.push_back(a.back());
                a.pop_back();
                cnt=1;
            } else {
                if (a.back()<b.back()) {
                    ans.push_back(a.back());
                    a.pop_back();
                    cnt=max(1, cnt+1);
                } else {
                    ans.push_back(b.back());
                    b.pop_back();
                    cnt=min(cnt-1, -1);
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}