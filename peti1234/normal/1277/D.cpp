#include <bits/stdc++.h>

using namespace std;
const int c=200002;
int ert[c], db[4], w, n;
string sz[c];
set<string> s;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n;
        db[0]=db[1]=db[2]=db[3]=0;
        s.clear();
        for (int i=1; i<=n; i++) {
            cin >> sz[i];
            int si=sz[i].size();
            s.insert(sz[i]);
            char x=sz[i][0], y=sz[i][si-1];
            int a=(x=='1'), b=(y=='1');
            ert[i]=2*a+b;
            db[ert[i]]++;
        }
        if (db[1]==0 && db[2]==0) {
            //cout << "spec: ";
            if (db[0] && db[3]) {
                cout << -1 << "\n";
            } else {
                cout << 0 << "\n\n";
            }
        } else {
            bool g=(db[2]>db[1]);
            int dif=abs(db[1]-db[2])/2;
            //cout << "valasz: ";
            cout << dif << "\n";
            for (int i=1; i<=n; i++) {
                if (dif && ert[i]==1+g) {
                    string rev=sz[i];
                    reverse(rev.begin(), rev.end());
                    if (s.find(rev)==s.end()) {
                        cout << i << " ";
                        dif--;
                    }
                }
            }
            cout << "\n";
        }
    }
    return 0;
}