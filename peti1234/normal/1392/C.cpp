#include <bits/stdc++.h>

using namespace std;
int w, n, el, x;
long long sum;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        cin >> n >> el, sum=0;
        for (int i=1; i<n; i++) {
            cin >> x;
            sum+=max(0, el-x), el=x;
        }
        cout << sum << "\n";
    }
    return 0;
}