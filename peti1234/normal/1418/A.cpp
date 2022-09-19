#include <bits/stdc++.h>

using namespace std;
long long a, b, c, w;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        cin >> a >> b >> c;
        cout << c+(c*(b+1)+a-3)/(a-1) << "\n";
    }
    return 0;
}