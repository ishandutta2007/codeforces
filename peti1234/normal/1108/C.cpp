#include <bits/stdc++.h>

using namespace std;
int n, db[3][3], maxi;
vector<int> p={0, 1, 2};
string s;
int main()
{
    cin >> n >> s;
    for (int i=0; i<n; i++) {
        int x=(s[i]=='R' ? 0 : s[i]=='G' ? 1 : 2);
        db[x][i%3]++;
    }
    do {
        maxi=max(maxi, db[p[0]][0]+db[p[1]][1]+db[p[2]][2]);
    } while (next_permutation(p.begin(), p.end()));
    do {
        if (db[p[0]][0]+db[p[1]][1]+db[p[2]][2]==maxi) {
            cout << n-maxi << "\n";
            for (int i=0; i<n; i++) {
                int s=p[i%3];
                cout << (s==0 ? 'R' : s==1 ? 'G' : 'B');
            }
            cout << "\n";
            return 0;
        }
    } while (next_permutation(p.begin(), p.end()));
    return 0;
}