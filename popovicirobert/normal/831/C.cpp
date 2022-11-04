#include <bits/stdc++.h>
#define MAXN 2000
#define MAXVAL 8000000

using namespace std;

int a[MAXN + 1], b[MAXN + 1];
int vf[2 * MAXVAL + 1];
bool f[2 * MAXVAL + 1];

int main() {
    //fstream cin("A.in");
    //ofstream cout("A.out");
    int i,n,k,j;
    ios::sync_with_stdio(false);
    cin >> k >> n;
    for(i = 1; i <= k; i++) {
        cin >> a[i];
        a[i] += a[i - 1];
      //  printf("%d " ,a[i]);
    }
    for(i = 1; i <= n; i++) {
        cin >> b[i];
        for(j = 1; j <= k; j++) {
            if(f[a[j] - b[i] + MAXVAL] == 0)
               vf[a[j] - b[i] + MAXVAL]++;
            f[a[j] - b[i] + MAXVAL] = 1;
          //  printf("%d\n" ,a[j] - b[i]);
        }
        for(j = 1; j <= k; j++)
            f[a[j] - b[i] + MAXVAL] = 0;
    }
    int ans = 0;
    for(i = 0; i <= 2 * MAXVAL; i++)
        if(vf[i] == n)
            ans++;
    cout << ans;
    //cin.close();
    //cout.close();
    return 0;
}