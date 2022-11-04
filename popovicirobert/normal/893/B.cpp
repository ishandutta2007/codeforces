#include <bits/stdc++.h>
#define lsb(x)
#define ll long long

using namespace std;

bool ok[4];

int main(){
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n, k;
    ios::sync_with_stdio(false);
    cin >> n;
    int ans = 0;
    for(i = 1; i <= n; i++) {
        if(n % i == 0)
          for(k = 1; k <= 15; k++)
              if(((1 << k) - 1) * (1 << (k - 1)) == i)
                  ans = max(ans, i);
    }
    cout << ans;
    //cin.close();
    //cout.close();
    return 0;
}