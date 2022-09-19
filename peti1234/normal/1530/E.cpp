#include <bits/stdc++.h>

using namespace std;
const int k=26;
int w, n, db[k];
string s;
void ki(int a) {
    char p='a'+a;
    cout << p;
    db[a]--;
}
void cl(int a) {
    while (db[a]) {
        ki(a);
    }
}
void solve() {
    int si=s.size(), pos=(s[0]-'a'), cnt=db[pos];
    if (si==1) {
        cl(pos);
        return;
    }

    int pos2=(s[1]-'a'), cnt2=db[pos2];
    for (int i=0; i<k; i++) {
        if (db[i]==1) {
            cl(i);
            for (int j=0; j<k; j++) {
                cl(j);
            }
            return;
        }
    }
    if (2*cnt<=n+2) {
        ki(pos), ki(pos);
        int id=pos+1;
        for (int j=2; j<n; j++) {
            if (j%2 && db[pos]) {
                ki(pos);
            } else {
                while (!db[id]) {
                    id++;
                }
                ki(id);
            }
        }
        return;
    }
    if (si>2) {
        ki(pos), ki(pos2);
        cl(pos);
        ki(s[2]-'a');
        for (int i=0; i<k; i++) {
            cl(i);
        }
        return;
    }
    if (si==2) {
        ki(pos);
        cl(pos2);
        cl(pos);
        return;
    }

}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> s;
        n=s.size();
        for (int i=0; i<n; i++) {
            db[s[i]-'a']++;
        }
        sort(s.begin(), s.end());
        string s2;
        for (auto x:s) {
            if (s2.size()==0 || x!=s2.back()) {
                s2+=x;
            }
        }
        swap(s, s2);
        solve();
        cout << "\n";
    }
    return 0;
}