#include <bits/stdc++.h>

using namespace std;
int w;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        int n, m, maxi=0, h=0, sum=0, fix=0;
        bool v=false;
        cin >> n >> m;
        for (int i=1; i<=n; i++) {
            int x;
            cin >> x;
            sum+=x;
            if (x>maxi) h=i, maxi=x;
            if (sum>m && !v) fix=h, v=true;
        }
        cout << fix << "\n";
    }
    return 0;
}