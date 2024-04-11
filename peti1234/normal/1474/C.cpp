#include <bits/stdc++.h>

using namespace std;
const int c=2002, k=1000002;
int w, n, x, t[c], db[k];
vector<int> sol;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n, n*=2;
        for (int i=1; i<=n; i++) {
            cin >> t[i];
        }
        sort(t+1, t+n+1);
        for (int i=1; i<n; i++) {
            for (int j=1; j<=n; j++) {
                db[t[j]]=0;
            }
            bool jo=1;
            for (int j=1; j<=n; j++) {
                db[t[j]]++;
            }
            sol.clear();
            x=t[n]+t[i];
            for (int j=n; j>=1; j--) {
                int s=t[j];
                if (db[s]) {
                    db[s]--;
                    sol.push_back(s), sol.push_back(x-s);
                    if (!db[x-s]) {
                        jo=0;
                        break;
                    } else {
                        db[x-s]--;
                    }
                    x=s;
                }
            }
            if (jo) {
                break;
            }
            sol.clear();
        }
        if (sol.size()>0) {
            cout << "YES\n";
            cout << sol[0]+sol[1] << "\n";
            for (int i=0; i<sol.size(); i++) {
                cout << sol[i] << " ";
                if (i%2) {
                    cout << "\n";
                }
            }
        } else {
            cout << "NO\n";
        }
        for (int i=1; i<=n; i++) {
            db[t[i]]=0;
        }
    }
    return 0;
}