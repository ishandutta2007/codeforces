#include <bits/stdc++.h>
#define MAXN 100

using namespace std;

int a[MAXN + 1];
bool viz[MAXN + 1];

int main() {
  //  fstream cin("A.in");
  //  ofstream cout("A.out");
    int i, n, k;
    ios::sync_with_stdio(false);
    cin >> n >> k;
    for(i = 1; i <= k; i++)
        cin >> a[i];
    int cnt = 0;
    int pos = 1;
    while(cnt < k) {
        i = pos;
        int x = a[cnt + 1] % (n - cnt);
        while(x > 0) {
            x--;
            i++;
            if(i > n)
                i = 1;
            while(viz[i] == 1) {
                i++;
                if(i > n)
                    i = 1;
            }
        }
        cnt++;
        viz[i] = 1;
        cout << i << " ";
        pos = i;
        while(viz[pos] == 1) {
            pos++;
            if(pos > n)
                pos = 1;
        }
    }
  //  cin.close();
  //  cout.close();
    return 0;
}