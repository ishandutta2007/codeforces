#include <bits/stdc++.h>
#define fi freopen("inp.txt", "r", stdin)
#define fo freopen("out.txt", "w", stdout)
#define MAX
#define N

using namespace std;

int sl[10];
string s;
int ss[7] = {1869, 6198, 1896, 1689, 1986, 1968, 1698};

int main() {
    ios_base::sync_with_stdio(0);
   // fi, fo;
    cin >> s;
    for(int i = 0; i < (int)s.size(); i++) sl[s[i] - '0']++;
    sl[1]--, sl[6]--, sl[8]--, sl[9]--;
    int c = 0;
    for(int i = 1; i <= 9; i++) {
        while(sl[i]--) {
            c = (c * 10 + i) % 7;
            cout << i;
        }
    }
    cout << ss[c];
    while(sl[0]--) cout << 0;
    return 0;
}