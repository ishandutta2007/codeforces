#include <bits/stdc++.h>

using namespace std;
int t;
long long sum;
int main()
{
    cin >> t;
    for (int i=1; i<=t; i++) {
        long long n, m;
        cin >> n >> m;
        long long a, b, c, d, e, f, g, h;
        cin >> a >> b >> c >> d >> e >> f >> g >> h;
        sum=(n*m+1)/2;
        if ((c-a+1)%2!=0 && (d-b+1)%2!=0) {
            if (a%2!=b%2) {
                sum++;
            }
        }
        sum+=(c-a+1)*(d-b+1)/2;
        //cout << "ABC" << sum << endl;
        if ((g-e+1)%2!=0 && (h-f+1)%2!=0) {
            if (e%2==f%2) {
                sum--;
            }
        }
        sum-=(g-e+1)*(h-f+1)/2;
        //cout << "ABC" << sum << endl;
        long long p, q, r, s;
        p=max(a, e);
        q=max(b, f);
        r=min(c, g);
        s=min(d, h);
        //cout << p << " " << q << " " << r << " " << s << endl;
        if (r>=p && s>=q) {
            if ((r-p+1)%2!=0 && (s-q+1)%2!=0) {

                if (p%2!=q%2) {
                    sum--;

                }
            }
            sum-=(r-p+1)*(s-q+1)/2;
        }
        cout << sum << " " << n*m-sum << endl;
    }
    return 0;
}
/*
1
3 4
2 2 3 2
3 1 4 3
*/