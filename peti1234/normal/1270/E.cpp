#include <bits/stdc++.h>

using namespace std;
const int c=1002;
vector<int> sol;
int n, x[c], y[c], ert[c], db[4];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> x[i] >> y[i];
        x[i]+=1e7, y[i]+=1e7;
        ert[i]=(2*(x[i]%2)+y[i]%2);
        db[ert[i]]++;
    }
    while(true) {
        int maxi=max({db[0], db[1], db[2], db[3]}), ps=db[1]+db[2];
        for (int i=0; i<4; i++) {
            db[i]=0;
        }
        if (maxi!=n) {
            if (ps!=0 && ps!=n) {
                for (int i=1; i<=n; i++) {
                    if (ert[i]%3) {
                        sol.push_back(i);
                    }
                }
            } else {
                for (int i=1; i<=n; i++) {
                    if (ert[i]<2) {
                        sol.push_back(i);
                    }
                }
            }
            break;
        }
        for (int i=1; i<=n; i++) {
            if (x[i]%2) {
                x[i]--;
            }
            if (y[i]%2) {
                y[i]--;
            }
            x[i]/=2, y[i]/=2;
            ert[i]=(2*(x[i]%2)+y[i]%2);
            db[ert[i]]++;
        }
    }
    cout << sol.size() << "\n";
    for (int i:sol) {
        cout << i << " ";
    }
    return 0;
}