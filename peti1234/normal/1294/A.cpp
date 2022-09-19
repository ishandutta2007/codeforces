#include <bits/stdc++.h>

using namespace std;
int w;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        int sum=a+b+c+d;
        if (sum%3==0 && a<=sum/3 && b<=sum/3 && c<=sum/3) cout << "YES" << "\n";
        else cout << "NO" << "\n";
    }
    return 0;
}