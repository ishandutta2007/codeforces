#include <bits/stdc++.h>
#define ll long long


using namespace std;

int cnt[16];

int fr[4];

int main() {
    //fstream cin("A.in");
    //ofstream cout("A.out");
    int n, k, i, cnf, j;
    ios::sync_with_stdio(false);
    cin >> n >> k;
    for(i = 1; i <= n; i++) {
        cnf = 0;
        for(j = 0; j < k; j++) {
            int bit;
            cin >> bit;
            cnf = (cnf << 1) + bit;
        }
        cnt[cnf]++;
    }
    for(cnf = 1; cnf < (1 << (1 << k)); cnf++) {
        memset(fr, 0, sizeof(fr));
        bool ok = 1;
        int nr = 0;
        for(i = 0; i < (1 << k); i++)
           if(cnf & (1 << i)) {
               nr++;
               if(cnt[i] > 0) {
                  for(j = 0; j < k; j++)
                     if(i & (1 << j))
                        fr[j]++;
               }
               else
                  ok = 0;
           }
        if(ok == 1) {
           for(i = 0; i < k; i++)
               if(fr[i] > nr / 2)
                   ok = 0;
           if(ok == 1) {
              // printf("%d\n" ,cnf);
               cout << "YES";
               return 0;
           }
        }
    }
    cout << "NO";
    //cin.close();
    //cout.close();
    return 0;
}