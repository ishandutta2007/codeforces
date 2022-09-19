#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int w;
    cin >> w;
    while (w--) {
        int n, jo=0;
        cin >> n;
        set<pair<string, int> > s;
        for (int i=1; i<=n; i++) {
            string x;
            cin >> x;
            int si=x.size();
            if (x[0]==x[si-1]) jo=1;
            else {
                string kezd=x.substr(0, 2), veg=x.substr(si-2, 2);
                reverse(veg.begin(), veg.end());
                if (s.find({veg, 5-si})!=s.end()) jo=1;
                s.insert({kezd, si}), s.insert({kezd, 3});
                if (si==3) {
                    if (s.find({x, 0})!=s.end()) jo=1;
                    reverse(x.begin(), x.end());
                    s.insert({x, 0});
                }
            }
        }
        cout << (jo ? "YES" : "NO") << "\n";
    }
    return 0;
}