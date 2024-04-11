#include <bits/stdc++.h>

using namespace std;
long long w, n, sum;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        long long a, b;
        cin >> a >> b;
        sum=a+b;
        for (int i=0; i<5; i++) {
            long long x;
            cin >> x;
            sum+=x;
        }
        cout << a << " " << b << " " << sum/4-a-b << "\n";
    }
    return 0;
}