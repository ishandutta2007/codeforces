#include <bits/stdc++.h>

using namespace std;
const int c=200005;
int n, m, st, d, t[c], dist[c];
bool v[c];
priority_queue<pair<int, pair<int, int> > > q;
set<int> s;
int tav(int a, int b) {
    return (abs(d-abs(t[a]-t[b])));
}
void pb(int a, int b) {
    if (1<=min(a, b) && max(a, b)<=n) {
        q.push({-max(dist[a], tav(a, b)), {a, b}});
    }
}
void add(int a) {
    v[a]=1;
    s.erase(a);
    int lo=1, hi=n+1, mid;
    while (hi-lo>1) {
        mid=(hi+lo)/2;
        if (t[a]-t[mid]>=d) {
            lo=mid;
        } else {
            hi=mid;
        }
    }
    auto it=s.upper_bound(lo);
    pb(a, *it), it--, pb(a, *it);
    lo=1, hi=n+1;
    while (hi-lo>1) {
        mid=(hi+lo)/2;
        if (t[mid]-t[a]>=d) {
            hi=mid;
        } else {
            lo=mid;
        }
    }
    it=s.lower_bound(hi);
    pb(a, *it), it--, pb(a, *it);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> st >> d;
    s.insert(0), s.insert(n+1);
    for (int i=1; i<=n; i++) {
        cin >> t[i];
        s.insert(i);
    }
    add(st);
    while (q.size()>0) {
        auto to=q.top();
        q.pop();
        int el=-to.first, a=to.second.first, b=to.second.second;
        if (!v[b]) {
            dist[b]=max(dist[a], el);

            add(b);
        }
        if (a<b) {
            if (t[b]-t[a]>=d) {
                auto it=s.upper_bound(b);
                if (*it!=n+1) {
                    pb(a, *it);
                }
            } else {
                auto it=s.lower_bound(b);
                it--;
                if (*it>a) {
                    pb(a, *it);
                }
            }
        } else {
            if (t[a]-t[b]>=d) {
                auto it=s.lower_bound(b);
                it--;
                pb(a, *it);
            } else {
                auto it=s.upper_bound(b);
                if (*it<a) {
                    pb(a, *it);
                }
            }
        }
    }
    while (m--) {
        int a, b;
        cin >> a >> b;
        cout << (dist[a]<=b ? "YES" : "NO") << "\n";
    }
    return 0;
}