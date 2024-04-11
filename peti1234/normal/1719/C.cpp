#include <bits/stdc++.h>

using namespace std;
const int c=100005;
int w, n, s, t[c], pos;
vector<int> sz[c];
deque<int> q;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n >> s;
        for (int i=1; i<=n; i++) {
            cin >> t[i];
            if (t[i]>t[pos]) pos=i;
            q.push_back(i);
        }
        for (int i=1; i<=n; i++) {
            int a=q.front(), b;
            q.pop_front();
            b=q.front();
            q.pop_front();
            if (t[a]<t[b]) swap(a, b);
            sz[a].push_back(i);
            q.push_front(a), q.push_back(b);
        }
        while (s--) {
            int id, k, cnt=0;
            cin >> id >> k;
            int lo=-1, hi=sz[id].size(), mid;
            while (hi-lo>1) {
                mid=(hi+lo)/2;
                if (sz[id][mid]<=k) lo=mid;
                else hi=mid;
            }
            int ans=hi;
            if (id==pos && k>n) ans+=k-n;
            //cout << "valasz......... ";
            cout << ans << "\n";
        }

        pos=0;
        q.clear();
        for (int i=1; i<=n; i++) sz[i].clear();

    }
    return 0;
}
/*
1
4 2
1 3 4 2
4 5
3 2
*/