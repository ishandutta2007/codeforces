#include <bits/stdc++.h>

using namespace std;
const int c=1000002;
int w, n, k, d, db[c], t[c], sum, mini;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n >> k >> d;
        for (int i=1; i<=n; i++) {
            cin >> t[i];
        }
        for (int i=1; i<=d; i++) {
            db[t[i]]++;
            if (db[t[i]]==1) {
                sum++;
            }
        }
        mini=sum;
        for (int i=d+1; i<=n; i++) {
            db[t[i]]++;
            if (db[t[i]]==1) {
                sum++;
            }
            db[t[i-d]]--;
            if (db[t[i-d]]==0) {
                sum--;
            }
            mini=min(mini, sum);
        }
        cout << mini << "\n";
        for (int i=1; i<=n; i++) {
            db[t[i]]=0;
        }
        sum=0;
    }
    return 0;
}