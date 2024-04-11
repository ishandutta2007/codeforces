#include <bits/stdc++.h>

using namespace std;
const int c=200005;
int w, n, el, cnt, ans, db[c];
vector<int> sz[c];
priority_queue<int> q, q2;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n;
        for (int i=1; i<=n; i++) {
            cin >> db[i];
            for (int j=0; j<db[i]; j++) {
                int x;
                cin >> x;
                sz[x].push_back(i);
            }
            if (!db[i]) {
                q.push(-i);
            }
        }
        el=n+1;
        while (q.size()>0 || q2.size()>0) {
            if (q.size()==0 || -q.top()<el) {
                while (q2.size()>0) {
                    q.push(q2.top());
                    q2.pop();
                }
            }
            int id=-q.top();
            cnt++;
            q.pop();
            if (id<el) {
                ans++;
            }
            el=id;
            for (auto x:sz[id]) {
                db[x]--;
                if (!db[x]) {
                    if (x>id) {
                        q.push(-x);
                    } else {
                        q2.push(-x);
                    }
                }
            }
        }
        //cout << "valasz...................... ";
        cout << (cnt==n ? ans : -1) << "\n";

        for (int i=1; i<=n; i++) {
            db[i]=0, sz[i].clear();
        }
        el=0, cnt=0, ans=0;
    }
    return 0;
}