#include <bits/stdc++.h>

using namespace std;
int n, cnt;
string a, b;
int main()
{
    cin >> n >> a >> b;
    for (int i=0; i<n; i++) {
        int f=n-1-i;
        if (i>f) break;
        char p=a[i], q=b[i], r=a[f], s=b[f];
        if (i==f) {
            if (p!=q) {
                cnt++;
            }
            break;
        }
        if (p==r && q==s) {
            continue;
        }
        int db=(p==q || r==q) + (p==s || r==s) ;
        cnt+=2-db;
        if (q==s && p!=r) {
            if (db==2) cnt++;
            else cnt--;
        }
    }
    cout << cnt << "\n";
    return 0;
}