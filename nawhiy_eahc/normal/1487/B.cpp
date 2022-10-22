#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        long long n, k;
        cin >> n >> k;
        if(n%2 == 0){
            long long ans = k%n;
            if(ans == 0) ans = n;
            cout << ans << "\n";
        }
        else{
            k = k%((n/2)*n);
            if(k == 0) cout << n-1 <<"\n";
            else if(k <= (n-1)/2) cout << k << "\n";
            else if(k <= n-1) cout << k + 1 << "\n";
            else{
                long long p = (k - n)/(n-2);
                long long d = (k - n + 1)%(n-2);
                if(d == 0) d = n-2;

                if(d <= p) cout << d << "\n";
                else if(d < p + (n+1)/2) cout << d + 1 << "\n";
                else cout << d + 2 << "\n";
            }
        }
    }
}