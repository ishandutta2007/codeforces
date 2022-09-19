#include <bits/stdc++.h>

using namespace std;
int w;
long long n;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n;
        while(n%2==0) {
            n/=2;
        }
        cout << (n==1? "NO" : "YES") << "\n";
    }
    return 0;
}