#include <bits/stdc++.h>

using namespace std;
int n, maxi;
multiset<int> s, s2;
set<int> p;
int main()
{
    cin >> n;
    for (int i=1; i<=n; i++) {
        int x;
        cin >> x;
        s.insert(x), p.insert(x);
    }
    for (auto i:p) {
        for (auto j:p) {
            int a=i, b=j;
            s2.insert(a);
            s.erase(s.find(a));
            int db=1;
            while (s.find(b)!=s.end()) {
                s2.insert(b);
                s.erase(s.find(b));
                int aa=b;
                db++;
                b=a+b, a=aa;
            }
            maxi=max(maxi, db);
            for (auto f:s2) {
                s.insert(f);
            }
            s2.clear();
        }
    }
    cout << maxi << "\n";
    return 0;
}