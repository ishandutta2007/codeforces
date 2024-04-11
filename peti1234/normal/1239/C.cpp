#include <bits/stdc++.h>

using namespace std;
long long n, p;
priority_queue<pair<long long, long long> > var;
priority_queue<long long> kesz;
priority_queue<long long> ki;
queue<long long> sor;
long long ans[100001];
bool v[100001];
long long t;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> p;
    for (long long i=1; i<=n; i++) {
        long long x;
        cin >> x;
        var.push({-x, -i});
    }
    while(var.size()>0 || kesz.size()>0 || sor.size()>0 || ki.size()>0) {
        while (sor.size()>0) {
            long long x=sor.front();
            sor.pop();
            t-=p;
            v[-x]=true;
            ans[-x]=-t;
            while(ki.size()>0 && v[-ki.top()]) {
                ki.pop();
            }
            if (kesz.size()>0) {
                int y=kesz.top();
                if ((ki.size()==0 || y>ki.top()) && y>x) {
                    ki.push(y);
                    sor.push(y);
                    kesz.pop();
                }
            }
            while(var.size()>0) {
                long long fi=var.top().first;
                long long se=var.top().second;
                if (fi>=t) {
                    var.pop();
                    if ((ki.size()==0 || se>ki.top()) && se>x) {
                        ki.push(se);
                        sor.push(se);
                    } else {
                        kesz.push(se);
                    }
                } else {
                    break;
                }
            }
            if (kesz.size()>0) {
                int x=kesz.top();
                if (ki.size()==0 || x>ki.top()) {
                    ki.push(x);
                    sor.push(x);
                    kesz.pop();
                }
            }
        }
        if (var.size()>0) {
            t=min(t, var.top().first);
        }
        while(var.size()>0) {
            long long fi=var.top().first;
            long long se=var.top().second;
            if (fi>=t) {
                if (sor.size()==0) {
                    sor.push(se);
                    ki.push(se);
                } else {
                    kesz.push(se);
                }
                var.pop();
            } else {
                break;
            }
        }
    }
    for (long long i=1; i<=n; i++) {
        cout << ans[i] << " ";
    }
    return 0;
}