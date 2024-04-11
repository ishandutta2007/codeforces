#include <bits/stdc++.h>

using namespace std;
long long n, k;
long long l, r;
long long p=47;
long long j=1;
int m=1;

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    r=n;
    l=1;
    while(m<=4500) {
        if (r-l<=100) {
            int a=r-l+1;
            cout.flush() << l+p%a << " " << l+p%a << endl;
            p%=a;
            string s;
            cin >> s;
            if (s=="Yes") {
                return 0;
            }
            l-=k;
            l=max(l, j);
            r+=k;
            r=min(r, n);
        } else {
            cout.flush() << l << " " << (r+l)/2 << endl;
            string s;
            cin >> s;
            if (s=="Yes") {
                r=(r+l)/2;
                r+=k;
                l-=k;
                l=max(l, j);
            } else {
                l=(r+l)/2-k;
                r=min(n, r+k);
            }

        }
        p+=1919+r-l;
        p%=1121;
        m++;
    }
    return 0;
}