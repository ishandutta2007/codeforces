#include <bits/stdc++.h>

using namespace std;
const int c=100002, k=5;
int n, m, s, t[c][k], maxi, pos, ans[k];
deque<int> q[k];
bool nagy() {
    int sum=0;
    for (int j=0; j<m; j++) {
        sum+=t[q[j].front()][j];
    }
    return (sum>s);
}
int main()
{
    cin >> n >> m >> s;
    for (int i=1; i<=n; i++) {
        for (int j=0; j<m; j++) cin >> t[i][j];
    }
    for (int i=1; i<=n; i++) {
        for (int j=0; j<m; j++) {
            while(q[j].size()>0 && t[i][j]>t[q[j].back()][j]) q[j].pop_back();
            q[j].push_back(i);
        }
        while(pos<i && nagy()) {
            pos++;
            for (int j=0; j<m; j++) {
                if (q[j].front()==pos) q[j].pop_front();
            }
        }
        if (i-pos>maxi) {
            maxi=i-pos;
            for (int j=0; j<m; j++) {
                ans[j]=t[q[j].front()][j];
            }
        }
    }
    for (int j=0; j<m; j++) {
        cout << ans[j] << " ";
    }
    return 0;
}