#include <bits/stdc++.h>

using namespace std;
long long w, a, b, c, o=0;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> a >> b >> c;
        cout << (max({o, b-a+1, c-a+1})) << " ";
        cout << (max({o, a-b+1, c-b+1})) << " ";
        cout << (max({o, a-c+1, b-c+1})) << "\n";
    }
    return 0;
}