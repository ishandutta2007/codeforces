#include <bits/stdc++.h>

using namespace std;
int db[7], n, m, k;
bool csa, csb;
string s;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> k;
    for (int i=1; i<=n; i++) {
        cin >> s;
        int pa=-1, pb=-1;
        for (int i=0; i<m; i++) {
            if (s[i]=='R') pa=i;
            if (s[i]=='G') pb=i;
        }
        if (pa==-1 && pb==-1) {
            continue;
        }
        if (pa==-1 && (m>2 || s[0]!='G' || s[1]!='G')) csa=1;
        else if (pb==-1 && (m>2 || s[0]!='R' || s[1]!='R')) csb=1;
        if (pa!=-1 && pb!=-1) {
            int tav=abs(pa-pb)-1;
            for (int i=0; i<7; i++) {
                if (tav & (1<<i)) {
                    db[i]++;
                }
            }
        }
    }
    if (m==1) cout << "Second\n";
    else {
        if (csa && csb) cout << "Draw\n";
        else if (csa) cout << "First\n";
        else if (csb) cout << "Second\n";
        else {
            for (int i=0; i<7; i++) {
                if (db[i]%(k+1)) {
                    cout << "First\n";
                    return 0;
                }
            }
            cout << "Second\n";
        }
    }
    return 0;
}