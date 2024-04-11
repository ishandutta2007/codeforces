#include <bits/stdc++.h>

using namespace std;
int w;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        long long a, b, c, db=0;
        cin >> a >> b >> c;
        if (a>b) swap(a, b);
        while(b<=c) a+=b, swap(a, b), db++;
        cout << db << "\n";
    }
    return 0;
}