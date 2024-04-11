#include <bits/stdc++.h>

using namespace std;
int w;
int a, b;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        cin >> a >> b;
        if (a<b) swap(a, b);
        int maxi=max(a, 2*b);
        cout << maxi*maxi << "\n";
    }
    return 0;
}