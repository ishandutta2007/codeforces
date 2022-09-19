#include <bits/stdc++.h>

using namespace std;
const int c=200005;
int w, n, p[c];
int main()
{
    ios_base::sync_with_stdio(false);
    int w;
    cin >> w;
    while (w--) {
        cin >> n;
        int cnt=0;
        for (int i=1; i<=n; i++) {
            char k;
            cin >> k;
            p[i]=(k=='1');
            cnt+=p[i];
        }
        if (cnt==0 || cnt%2) {
            cout << "NO\n";
            continue;
        } else {
            cout << "YES\n";
            vector<int> sz;
            int kezd=0;
            for (int i=1; i<=n; i++) {
                if (p[i]) {
                    kezd=i;
                }
            }
            for (int i=0; i<n; i++) {
                int a=kezd+i;
                if (a>n) a-=n;
                int si=sz.size();
                if (i==n-1) {
                    while (si>0) {
                        cout << sz.back() << " " << a << "\n";
                        sz.pop_back();
                        si--;
                    }
                } else {
                    while (p[a]+si>2) {
                        for (int j=0; j<2; j++) {
                            cout << sz.back() << " " << a << "\n";
                            sz.pop_back();
                        }
                        si-=2;
                    }
                    if (p[a]) {
                        sz.push_back(a);
                    } else {
                        cout << sz.back() << " " << a << "\n";
                        sz.back()=a;
                    }
                }
            }
        }
    }
    return 0;
}