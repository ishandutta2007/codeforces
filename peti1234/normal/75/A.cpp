#include <bits/stdc++.h>

using namespace std;
long long a, b, c;
long long calc(long long a) {
    long long ans=0, po=1;
    while (a) {
        if (a%10) {
            ans+=a%10*po;
            po*=10;
        }
        a/=10;
    }
    return ans;
}
int main()
{
    cin >> a >> b;
    c=a+b;
    cout << (calc(a)+calc(b)==calc(c) ? "YES" : "NO") << "\n";
    return 0;
}