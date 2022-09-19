#include <bits/stdc++.h>

using namespace std;
long long n;
long long sum;
long long t[100002];
int main()
{
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
    }
    for (long long i=1; i<=n; i++) {
        long long a=t[i];
        long long b=t[i+1];
        if (a==b) {
            continue;
        }
        if (b>a) {
            sum+=(b-a)*a;
        }
        if (a>b) {
            sum+=(a-b)*(n+1-a);
        }
    }
    cout << sum << endl;
    return 0;
}