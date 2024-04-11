#include <bits/stdc++.h>

using namespace std;
int a[100002], b[100002], inva[100002];

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int n; cin >> n;
    for(int i=1;i<=n;i++) cin >> a[i];
    for(int i=1;i<=n;i++) cin >> b[i];
    for(int i=1;i<=n;i++) inva[a[i]] = i;
    stack<int> s; int cnt = 0;
    for(int i=1;i<=n;i++){
        while(!s.empty() && inva[s.top()] > inva[b[i]]){
            s.pop(); cnt++;
        }
        s.push(b[i]);
    }

    cout << cnt;
}