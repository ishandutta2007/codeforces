#include <bits/stdc++.h>

using namespace std;
int w;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        int n; cin >> n;
        if (n==1 || n==2 || n==4) cout << -1 << "\n";
        else if (n==7) cout << "0 0 1\n";
        else cout << (n-5*((2*n)%3))/3 << " " << (2*n)%3 << " " << 0 << "\n";
    }
    return 0;
}