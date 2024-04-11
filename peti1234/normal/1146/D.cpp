#include <bits/stdc++.h>

using namespace std;
const int c=200002;
long long e, h, n, s, maxi, sum;
bool v[c];
priority_queue<pair<int, int> > q;
long long ert(long long p) {
    long long ans=0;
    ans+=(p%s+1)*(p/s);
    p-=p%s;
    ans+=((p-1)/s)*p/2;
    return ans;
}

int main()
{
    cin >> maxi >> e >> h, sum=maxi+1;
    n=e+h, s=__gcd(e, h),
    n=min(n, maxi);
    sum+=ert(maxi)-ert(n);
    q.push({-e, e});
    while(q.size()) {
        long long ert=-q.top().first, id=q.top().second;
        q.pop();
        if (id>0 && id<=n && ert<=n && !v[id]) {
            v[id]=1;
            sum+=n+1-ert;
            q.push({-ert, id-h});
            q.push({min(-ert, -id-e), id+e});
        }
    }
    cout << sum << "\n";
    return 0;
}