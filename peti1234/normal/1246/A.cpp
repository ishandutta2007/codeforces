#include <bits/stdc++.h>
 
using namespace std;
long long n, p;
long long db(long long n)
{
    long long ans=0;
    while(n>0) {
        if (n%2) {
            ans++;
        }
        n/=2;
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> p;
    for (long long i=1;; i++) {
        n-=p;
        if (n<=0) {
            cout << -1 << "\n";
            return 0;
        }
        if (db(n)<=i && n>=i) {
            cout << i << "\n";
            return 0;
        }
    }
    return 0;
}