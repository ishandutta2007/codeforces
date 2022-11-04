#include <bits/stdc++.h>
#define MAXN 300000

using namespace std;

int v[MAXN + 1];

bool in[MAXN + 1];


std::set <int> ms;

string str;

int main() {
  //  fstream cin("A.in");
  //  ofstream cout("A.out");
    int i, n, x;
    ios::sync_with_stdio(false);
    cin >> n;
    int sz = 0, ans = 0;
    int val = 1;
    for(i = 1; i <= 2 * n; i++) {
        str.clear();
        cin >> str;
        if(str[0] == 'a') {
            cin >> x;
            v[++sz] = x;
            in[x] = 1;
        }
        else {
            if(in[val] == 0) {
                cout << -1 << endl;
                return 0;
            }
            else {
                if(sz == 0)
                    ms.erase(ms.find(val));
                else {
                    if(v[sz] == val)
                        sz--;
                    else {
                        ans++;
                        while(sz > 0) {
                            ms.insert(v[sz]);
                            sz--;
                        }
                        ms.erase(ms.find(val));
                    }
                }
            }
            val++;
        }
    }
    cout << ans;
   // cin.close();
   // cout.close();
    return 0;
}