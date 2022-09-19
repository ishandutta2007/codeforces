#include <bits/stdc++.h>

using namespace std;
int w;
long long n, k, x, res[2005];
string a;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n >> k >> x;
        cin >> a;
        x--;
        int db=0;
        for (int i=n-1; i>=0; i--) {
            if (a[i]=='*') {
                db++;
                if (i==0 || a[i-1]=='a') {
                    long long s=k*db+1;
                    res[i]=x%s;
                    x/=s;
                    db=0;
                }
            }
        }

        for (int i=0; i<n; i++) {
            if (a[i]=='a') cout << a[i];
            else {
                for (int j=0; j<res[i]; j++) {
                    cout << 'b';
                }
            }
        }
        cout << "\n";
        for (int i=0; i<=n; i++) {
            res[i]=0;
        }
    }
    return 0;
}