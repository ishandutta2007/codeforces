#include <bits/stdc++.h>

using namespace std;
long long t[100001];
int main()
{
    long long n;
    cin  >> n;
    for (long long i=1; i<=n; i++) {
        cin >> t[i];
    }
    for (long long i=1; i<=n; i++) {
        long long a=t[i];
        long long b=sqrt(2*a);
        if (b*b+b>2*a) {
            //cout << b << " " << a << endl;
            b--;
            cout << max({b*(b-1)/2+a-b, (a-b-1)*2, }) << endl;
            continue;
        }
        cout << max((b*(b-1)/2)+a-b, (a-b-1)*2) << endl;
    }
    return 0;
}