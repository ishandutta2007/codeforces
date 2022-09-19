#include <bits/stdc++.h>

using namespace std;
int n;
int main()
{
    cin >> n;
    for (int i=1; i<=n; i++) {
        long long a;
        cin >> a;
        long long q=1;
        while(a>0) {
            if (a%2==1) {
                q*=2;
            }
            a/=2;
        }
        cout << q << endl;
    }
    return 0;
}