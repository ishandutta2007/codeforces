#include <bits/stdc++.h>

using namespace std;
bool jo(int a, int b) {
    while (a>b) {
        a/=2;
    }
    return a==b;
}
int main()
{
    ios_base::sync_with_stdio(false);
    int w;
    cin >> w;
    while (w--) {
        int n;
        cin >> n;
        map<int, int> m;
        for (int i=1; i<=n; i++) {
            int x;
            cin >> x;
            m[x]++;
        }
        for (int i=n; i>=1; i--) {
            for (auto j:m) {
                if (j.second>0 && jo(j.first, i)) {
                    m[j.first]--;
                    break;
                }
            }
        }
        int sum=0;
        for (auto j:m) {
            sum+=j.second;
        }
        cout << (sum==0 ? "YES" : "NO") << "\n";
    }
    return 0;
}