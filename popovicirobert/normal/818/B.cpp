#include <bits/stdc++.h>


using namespace std;

int l[101], a[101];
bool f[101];

int main() {
    //fstream cin("A.in");
    //ofstream cout("A.out");
    int n, m, i;
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for(i = 1; i <= m; i++)
        cin >> l[i];
    for(i = 1; i < m; i++) {
        int aux = a[l[i]];
        a[l[i]] = l[i + 1] - l[i];
        if(a[l[i]] <= 0)
            a[l[i]] += n;
        if(aux > 0 && aux != a[l[i]]) {
            cout << -1;
            return 0;
        }
    }
    for(i = 1; i <= n; i++)
       if(f[a[i]] == 1 && a[i] > 0) {
           cout << -1;
           return 0;
       }
       else
           f[a[i]] = 1;
    int val = 1;
    for(i = 1; i <= n; i++)
       if(a[i] == 0) {
          while(f[val] == 1)
             val++;
          a[i] = val;
          f[val] = 1;
       }
    for(i = 1; i <= n; i++)
        cout << a[i] << " ";
    //cin.close();
    //cout.close();
    return 0;
}