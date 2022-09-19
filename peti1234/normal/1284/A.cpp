#include <bits/stdc++.h>

using namespace std;
int a, b, w;
string x[22], y[22];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> a >> b;
    for (int i=0; i<a; i++) cin >> x[i];
    for (int i=0; i<b; i++) cin >> y[i];
    cin >> w;
    while(w--) {
        int db;
        cin >> db;
        db--;
        cout << x[db%a] << y[db%b] << "\n";
    }
    return 0;
}