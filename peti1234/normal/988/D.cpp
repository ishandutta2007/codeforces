#include <bits/stdc++.h>

using namespace std;
int n;
set<int> s;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=n; i++) {
        int x;
        cin >> x;
        s.insert(x);
    }
    for (auto x:s) {
        for (int po=0; po<=30; po++) {
            int p=(1<<po);
            if (s.find(x-p)!=s.end() && s.find(x+p)!=s.end()) {
                cout << 3 << "\n" << x << " " << x-p << " " << x+p << "\n";
                return 0;
            }
        }
    }
    for (auto x:s) {
        for (int po=0; po<=30; po++) {
            int p=(1<<po);
            if (s.find(x-p)!=s.end()) {
                cout << 2 << "\n" << x << " " << x-p << "\n";
                return 0;
            }
        }
    }
    for (auto x:s) {
        cout << 1 << "\n" << x << "\n";
        return 0;
    }
    return 0;
}