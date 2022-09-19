#include <bits/stdc++.h>

using namespace std;
long long n, x, ans;
priority_queue<int> q;
int main()
{
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> x;
        x-=i;
        q.push(x), q.push(x);
        ans+=q.top()-x;
        q.pop();
    }
    cout << ans << "\n";
    return 0;
}