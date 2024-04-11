#include <bits/stdc++.h>

using namespace std;
int w, n, cnt;
set<int> s;
int main()
{
    cin >> w;
    while (w--) {
        cin >> n;
        cnt=0;
        for (int i=1; i<=n; i++) {
            int x;
            cin >> x;
            if (x%2==0) {
                s.insert(x);
            }
        }
        while (s.size()>0) {
            auto p=s.end();
            p--;
            int ert=*p;
            cnt++;
            s.erase(ert);
            ert/=2;
            if (ert%2==0) {
                s.insert(ert);
            }
        }
        cout << cnt << "\n";
    }
    return 0;
}