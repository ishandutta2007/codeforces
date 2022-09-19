#include <bits/stdc++.h>

using namespace std;
const int c=200005;
long long w, n, k, sum, db[1005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n >> k;
        sum=0;
        for (int i=1; i<=n; i++) {
            long long x;
            cin >> x;
            sum+=(x/k);
            db[x%k]++;

        }
        int pos=k-1;
        for (int i=1; i<=pos; i++) {
            while (db[i]) {
                while (pos && db[pos]==0) pos--;
                if (i+pos<k) break;
                if (i==pos) {
                    while (db[i]>1) {
                        db[i]-=2;
                        sum++;
                    }
                    break;
                }
                while (db[i] && db[pos]) {
                    db[i]--, db[pos]--;
                    sum++;
                }
            }
        }
        cout << sum << "\n";
        for (int i=0; i<k; i++) {
            db[i]=0;
        }
    }
    return 0;
}