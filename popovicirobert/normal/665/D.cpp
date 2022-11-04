#include <bits/stdc++.h>
#define MAXN 1000
#define MAXVAL 2000010

using namespace std;

int v[MAXN + 1];
bool ciur[MAXVAL + 1];
int fr[MAXVAL + 1];

int main() {
    //fstream cin("A.in");
    //ofstream cout("A.out");
    int i, n, j;
    ios::sync_with_stdio(false);
    cin >> n;
    for(i = 1; i <= n; i++) {
        cin >> v[i];
        fr[v[i]]++;
    }
    for(i = 2; i * i <= MAXVAL; i++)
        if(ciur[i] == 0)
           for(j = i * i; j <= MAXVAL; j += i)
               ciur[j] = 1;
    int ans = max(fr[1], 1);
    for(i = 1; i <= n; i++)
        if(v[i] != 1 && ciur[v[i] + 1] == 0) {
            ans = fr[1] + 1;
            break;
        }
    bool flag = 0;
    for(i = 1; i <= n; i++)
        for(j = i + 1; j <= n; j++)
            if(ciur[v[i] + v[j]] == 0) {
               ans = max(ans, 2);
               if(ans == 2)
                  flag = 1;
            }
    cout << ans << endl;
    if(flag == 1) {
        for(i = 1; i <= n; i++)
          for(j = i + 1; j <= n; j++)
            if(ciur[v[i] + v[j]] == 0) {
                cout << v[i] << " " << v[j];
                return 0;
            }
    }
    else if(ans > 1) {
        for(i = 1; i <= fr[1]; i++)
            cout << 1 << " ";
        for(i = 1; i <= n; i++)
           if(v[i] > 1 && ciur[v[i] + 1] == 0) {
               cout << v[i];
               return 0;
           }
    }
    else
            cout << v[1];
   // cin.close();
    //cout.close();
    return 0;
}