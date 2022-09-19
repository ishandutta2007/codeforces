#include <bits/stdc++.h>

using namespace std;
int w, n, ans;
map<int, int> m;
void ch(int ert, int p) {
    if (ans>=ert) {
        return;
    }
    int cnt=0;
    for (auto x:m) {
        if (abs(x.first-p)%ert==0) {
            cnt+=x.second;
        }
    }
    if (2*cnt>=n) {
        ans=max(ans, ert);
    }
}
int main()
{
    cin >> w;
    while (w--) {
        cin >> n;
        for (int i=1; i<=n; i++) {
            int x;
            cin >> x;
            m[x]++;
        }
        bool spec=0;
        for (auto x:m) {
            if (2*x.second>=n) {
                spec=1;
            }
        }
        if (spec) {
            cout << -1 << "\n";
        } else {
            for (auto x:m) {
                for (auto y:m) {
                    int dif=abs(y.first-x.first);
                    if (dif!=0) {
                        for (int i=1; i*i<=dif; i++) {
                            if (dif%i==0) {
                                ch(i, x.first);
                                ch(dif/i, x.first);
                            }
                        }
                    }
                }
            }
            cout << ans << "\n";
        }
        m.clear();
        ans=0;
    }
    return 0;
}
/*
1
8
-1 0 1 -1 0 1 -1 0
*/