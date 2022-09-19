#include <bits/stdc++.h>

using namespace std;
long long n, jo, rossz, ans, x;
priority_queue<int> q;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    ans=n;
    for (int i=1; i<=n; i++) {
        cin >> x;
        if (x>0) {
            jo+=x;
        } else {
            x*=-1;
            rossz+=x;
            q.push(x);
            if (rossz>jo) {
                rossz-=q.top();
                q.pop();
                ans--;
            }
        }
    }
    cout << ans << "\n";
    return 0;
}