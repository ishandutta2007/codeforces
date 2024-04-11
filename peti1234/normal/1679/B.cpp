#include <bits/stdc++.h>

using namespace std;
const int c=200005;
long long n, q, t[c], sum, ut;
vector<int> spec;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> q;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
        spec.push_back(i);
        sum+=t[i];
    }
    for (int i=1; i<=q; i++) {
        int id;
        cin >> id;
        if (id==1) {
            int a, b;
            cin >> a >> b;
            if (!t[a]) t[a]=ut;
            sum+=b-t[a];
            t[a]=b;
            spec.push_back(a);
        } else {
            int x;
            cin >> x;
            ut=x, sum=n*x;
            for (auto p:spec) {
                t[p]=0;
            }
            spec.clear();
        }
        cout << sum << "\n";
    }
    return 0;
}