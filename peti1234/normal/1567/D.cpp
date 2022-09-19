#include <bits/stdc++.h>

using namespace std;
const int c=15;
long long w, n, s, db[c], sum;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> s >> n;
        for (int i=1; s>0; i++) {
            db[i]=s%10;
            sum+=db[i];
            s/=10;
        }
        while (sum<n) {
            for (int i=2; i<c; i++) {
                if (db[i]) {
                    db[i]--, db[i-1]+=10;
                    sum+=9;
                    break;
                }
            }
        }
        for (int i=1; i<=n; i++) {
            int ert=0, po=1;
            for (int j=1; j<c; j++) {
                while (db[j] && sum>n-i) {
                    db[j]--;
                    ert+=po;
                    sum--;
                }
                po*=10;
            }
            cout << ert << " ";
        }
        cout << "\n";

        sum=0;
    }
    return 0;
}
/*
1
111 4
*/