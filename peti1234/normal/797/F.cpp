#include <bits/stdc++.h>

using namespace std;
const int c=10105;
long long n, m, regi[c], uj[c], f=5002, el=-1e9, sok=1e18;
vector<pair<long long, long long> > sz;
deque<int> q;
int main()
{
    /*ios_base::sync_with_stdio(false);
    cin.tie(0);*/
    cin >> n >> m;
    for (int i=1; i<=n; i++) {
        int x;
        cin >> x;
        sz.push_back({x, 0});
    }
    for (int i=1; i<=m; i++) {
        int a, b;
        cin >> a >> b;
        sz.push_back({a, b});
    }
    sort(sz.begin(), sz.end());
    for (int i=f-n; i<=f+n; i++) {
        regi[i]=sok, uj[i]=sok;
    }
    regi[f]=0;
    for (auto x:sz) {
        long long dist=x.first-el;
        for (int i=f-n; i<=f+n; i++) {
            regi[i]+=dist*abs(i-f);
        }
        el=x.first;
        int ert=x.second;
        if (ert==0) {
            for (int i=f-n; i<f+n; i++) {
                uj[i+1]=regi[i];
            }
        } else {
            for (int i=f+n; i>=f-n; i--) {
                while (q.size()>0 && regi[i]<regi[q.front()]) {
                    q.pop_front();
                }
                q.push_front(i);
                uj[i]=regi[q.back()];
                if (q.back()-i==ert) {
                    q.pop_back();
                }
            }
            q.clear();
        }

        for (int i=f-n; i<=f+n; i++) {
            regi[i]=uj[i];
            uj[i]=sok;
        }
    }
    cout << (regi[f]>=sok ? -1 : regi[f]) << "\n";
    return 0;
}