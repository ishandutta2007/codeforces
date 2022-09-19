#include <bits/stdc++.h>

using namespace std;
bool jo(int a, int b) {
    if (a<=0 || a%b) return 0;
    return 1;
}
int main()
{
    ios_base::sync_with_stdio(false);
    int w;
    cin >> w;
    while (w--) {
        int a, b, c;
        cin >> a >> b >> c;
        if (jo(2*b-a, c) || jo(2*b-c, a) || (a+c)%2==0 && jo((a+c)/2, b)) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}