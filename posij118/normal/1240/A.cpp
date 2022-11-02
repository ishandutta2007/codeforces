#include <bits/stdc++.h>
using namespace std;

int main(){
    int q;
    cin >> q;

    while(q--){
        int n;
        cin >> n;

        int p[n];
        long long pr[n + 1];
        for(int i = 0; i<n; i++){
            cin >> p[i];
        }

        sort(p, p + n);
        reverse(p, p + n);
        pr[0] = 0;
        for(int i = 1; i<=n; i++){
            pr[i] = pr[i - 1] + p[i - 1];
        }

        long long x, a;
        cin >> x >> a;

        long long y, b;
        cin >> y >> b;

        long long k, cur;
        cin >> k;

        int d = 0;
        int h = n + 1;

        while(h > d + 1){
            cur = 0;
            int mid = (d + h) / 2;

            int both = mid / ((a*b) / __gcd(a, b));
            int xx = mid / a - both;
            int yy = mid / b - both;

            if(x > y){
                cur += ((pr[both] - pr[0])/100) * (x + y);
                cur += ((pr[both + xx] - pr[both])/100) * (x);
                cur += ((pr[both + xx + yy] - pr[both + xx])/100) * (y);
            }

            else{
                cur += ((pr[both] - pr[0])/100) * (x + y);
                cur += ((pr[both + yy] - pr[both])/100) * (y);
                cur += ((pr[both + xx + yy] - pr[both + yy])/100) * (x);
            }

            if(cur >= k) h = mid;
            else d = mid;
        }

        if(h == n + 1) cout << -1 << endl;
        else cout << h << endl;
    }
}