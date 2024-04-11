#include <bits/stdc++.h>
 
using namespace std;
string a, b;
int n, m;
int ans;
int db;
int k;
int main()
{
    cin >> a >> b;
    n=a.size(), m=b.size();
    a+='0';
    for (int i=0; i<m; i++) {
        if (a[i]!=b[i]) {
            db++;
        }
        if (i+1<n) {
            if (a[i]!=a[i+1]) {
                k++;
            }
        }
    }
    if (!(db%2)) {
        ans++;
    }
    for (int i=0; i<n-m; i++) {
        if (k%2) {
            db++;
        }
        if (!(db%2)) {
            ans++;
        }
        if (a[i]!=a[i+1]) {
            k++;
        }
        if (a[m+i]!=a[m+i+1]) {
            k++;
        }
    }
    cout << ans << endl;
    return 0;
}