#include <bits/stdc++.h>

using namespace std;
int w;
long long a, b, c, d, e, f;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        cin >> a >> b >> c >> d, e=c-a, f=d-b;
        cout << e*f+1 << "\n";
    }
    return 0;
}