#include <bits/stdc++.h>
#define MAXN 1000

using namespace std;

int v[MAXN + 1];
int sol[MAXN + 1];

int main() {
  //  fstream cin("B.in");
  //  ofstream cout("B.out");
    int n, i;
    ios::sync_with_stdio(false);
    cin >> n;
    for(i = 1; i <= n; i++)
        cin >> v[i];
    sort(v + 1, v + n + 1);
    int p = n;
    for(i = (n / 2) * 2; i > 0; i -= 2)
        sol[i] = v[p--];
    if(n % 2 == 0)
        i = n - 1;
    else
        i = n;
    for(; i > 0; i -= 2)
        sol[i] = v[p--];
    sol[0] = (1 << 30);
    for(i = 1; i <= n; i++) {
        if(i % 2 == 1) {
            if(sol[i] > sol[i - 1]) {
                cout << "Impossible";
                return 0;
            }
        }
        else {
            if(sol[i] < sol[i - 1]) {
                cout << "Impossible";
                return 0;
            }
        }
    }
    for(i = 1; i <= n; i++)
        cout << sol[i] << " ";
  //  cin.close();
  //  cout.close();
    return 0;
}