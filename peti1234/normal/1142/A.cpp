#include <bits/stdc++.h>

using namespace std;
long long n, k, a, b;
long long x, y;
long long mini=100000000000, maxi=0;
long long gcd(long long a, long long b)
{
    if (a>b) {
        swap(a, b);
    }
    if (a==0) {
        return b;
    }
    return gcd(a, b%a);
}
void ask(long long a, long long b)
{
    long long c=abs(a-b);
    long long d=n*k/gcd(n*k, c);
    mini=min(mini, d);
    maxi=max(maxi, d);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> k >> a >> b;
    x=a+1, y=k+1-a;
    for (long long i=0; i<n; i++) {
        long long p, q;
        p=i*k+1+b;
        q=(i+1)*k+1-b;
        ask(x, p);
        ask(x, q);
        ask(y, p);
        ask(y, q);
    }
    cout << mini << " " << maxi << "\n";
    return 0;
}