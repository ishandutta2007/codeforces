#include <bits/stdc++.h>

using namespace std;
int w, n;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        int a=0, b=0, c=0;
        cin >> n;
        for (int i=2; i*i<=n; i++) {
            if (n%i==0) {
                n/=i;
                if (!a) a=i;
                else b=i, c=n, n=0;
            }
        }
        if (b==c || !c) cout << "NO" << "\n";
        else cout << "YES" << "\n" << a << " " << b << " " << c << "\n";
    }
    return 0;
}