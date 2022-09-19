#include <bits/stdc++.h>

using namespace std;
int w;
int main()
{
    cin >> w;
    while (w--) {
        int a, b;
        cin >> a >> b;
        int c=abs(a-b);
        int sum=c/5;
        c%=5;
        sum+=c/2;
        sum+=c%2;
        cout << sum << "\n";
    }
    return 0;
}