#include <bits/stdc++.h>
#define MAXVAL 1000000
#define MAXN 100000

using namespace std;

set < pair <int, int> > ms;

int v[MAXN + 1];
int fr[MAXVAL + 1];

int main() {
   // fstream cin("A.in");
   // ofstream cout("A.out");
    int i,n,a,x,cnt;
    ios::sync_with_stdio(false);
    cin >> n >> a;
    for(i = 1; i <= n; i++) {
       cin >> v[i];
       ms.insert({0, v[i]});
    }
    for(i = 1; i <= n; i++) {
        x = v[i];
        if(x == a) {
            fr[x]++;
            while(!ms.empty() && ms.begin() -> first < fr[a]) {
                if(ms.begin() -> second != a)
                   fr[ms.begin() -> second] = -n;
                ms.erase(ms.begin());
            }
        }
        else {
            if(fr[x] >= 0) {
               ms.erase(ms.find({fr[x], x}));
               fr[x]++;
               ms.insert({fr[x], x});
            }
        }
    }
    if(ms.empty())
        cout << -1;
    else
        cout << ms.begin() -> second;
  //  cin.close();
   // cout.close();
    return 0;
}