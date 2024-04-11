#include <bits/stdc++.h>

using namespace std;
int n, x, y;
long long mod=1000000007;
long long sum;
vector<pair<int, int> > t;
priority_queue<long long> v;
priority_queue<long long> q;

int main()
{
    cin >> n >> x >> y;
    for (int i=1; i<=n; i++) {
        int a, b;
        cin >> a >> b;
        t.push_back({a, b});
    }
    sort(t.begin(), t.end());
    for (int i=0; i<n; i++) {
        long long a=t[i].first;
        long long b=t[i].second;
        while(v.size()>0 && -v.top()<a) {
            q.push({-v.top()});
            v.pop();
        }
        if (q.size()==0 || (a-q.top())*y>=x) {
            sum+=x;
            while(q.size()>0) {
                q.pop();
            }
        } else {
            sum+=(a-q.top())*y;
            q.pop();
        }
        v.push(-b);
        sum+=(b-a)*y;
        sum%=mod;
    }
    cout << sum << endl;
    return 0;
}