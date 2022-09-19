#include <bits/stdc++.h>
 
using namespace std;
bool v[502][502];
int n, m, x, y;
string s;
int sum=1;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> x >> y;
    v[x][y]=true;
    cin >> s;
    cout << 1 << " ";
    for (int i=0; i<s.size(); i++) {
        char c=s[i];
        if (c=='U' && x!=1) {
            x--;
        }
        if (c=='D' && x!=n) {
            x++;
        }
        if (c=='L' && y!=1) {
            y--;
        }
        if (c=='R' && y!=m) {
            y++;
        }
        if (i+1==s.size()) {
            cout << n*m-sum << "\n";
            return 0;
        }
        if (!v[x][y]) {
            v[x][y]=true;
            sum++;
            cout << 1 << " ";
        } else {
            cout << 0 << " ";
        }
    }
    return 0;
}