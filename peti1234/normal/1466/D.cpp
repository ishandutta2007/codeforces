#include <bits/stdc++.h>

using namespace std;
const int c=200005;
long long q, n, db[c], w[c], sum;
vector<long long> s;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> q;
    while(q--) {
        cin >> n;
        s.clear(), sum=0;
        for (int i=1; i<=n; i++) {
            cin >> w[i];
            sum+=w[i];
            db[i]=0;
        }
        for (int i=1; i<n; i++) {
            int a, b; cin >> a >> b;
            db[a]++, db[b]++;
            if (db[a]>1) {
                s.push_back(w[a]);
            }
            if (db[b]>1) {
                s.push_back(w[b]);
            }
        }
        sort(s.rbegin(), s.rend());
        cout << sum << " ";
        for (long long i:s) {
            sum+=i;
            cout << sum << " ";
        }
        cout << "\n";
    }
    return 0;
}