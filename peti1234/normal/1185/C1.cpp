#include <bits/stdc++.h>

using namespace std;
int n, m, sum, cnt;
priority_queue<int> a;
priority_queue <int, vector<int>, greater<int> > b;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i=1; i<=n; i++) {
        int x;
        cin >> x;
        while (sum+x>m || (a.size()>0 && b.size()>0 && a.top()>b.top())) {
            sum-=a.top();
            cnt++;
            b.push(a.top());
            a.pop();
        }
        while (b.size()>0 && sum+x+b.top()<=m) {
            sum+=b.top();
            cnt--;
            a.push(b.top());
            b.pop();
        }
        cout << cnt << " ";
        b.push(x);
        cnt++;
    }
    return 0;
}
/*
2 15
1 2
*/