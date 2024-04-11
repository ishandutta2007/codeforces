#include <bits/stdc++.h>

using namespace std;
int w, n;
int main()
{
    cin >> w;
    while(w--) {
        cin >> n;
        long long sum=0;
        for (int i=1; ; i++) {
            sum+=i;
            if (sum>=n) {
                if (sum==n+1) cout << i+1 << "\n";
                else cout << i << "\n";
                break;
            }
        }
    }
    return 0;
}