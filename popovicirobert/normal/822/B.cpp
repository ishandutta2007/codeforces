#include <bits/stdc++.h>


using namespace std;

string a, b;

int main() {
    //fstream cin("A.in");
    //ofstream cout("A.out");
    int i,j,n,m,poz;
    ios::sync_with_stdio(false);
    cin >> n >> m;
    cin >> a;
    cin >> b;
    int ans = n + m;
    for(i = 0; i < m; i++)
      if(i + n - 1 < m){
        j = 0;
        int cnt = 0;
        while(j < n) {
            if(a[j] != b[i + j])
               cnt++;
            j++;
        }
        if(ans > cnt) {
            ans = cnt;
            poz = i;
        }
      }
    cout << ans << endl;
    for(j = 0; j < n; j++)
        if(a[j] != b[poz + j])
          cout << j + 1 << " ";
    //cin.close();
   // cout.close();
    return 0;
}