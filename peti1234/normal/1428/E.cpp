#include <bits/stdc++.h>

using namespace std;
const long long c=100002;
long long n, k, t[c], db[c];
long long sum;
long long p(long long a, long long b) {
    long long s=a/b, l=a%b;
    return (s+1)*(s+1)*l+s*s*(b-l);
}
priority_queue<pair<long long, int> > q;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    k-=n;
    for (long long i=1; i<=n; i++) {
        cin >> t[i];
        q.push({p(t[i], 1)-p(t[i], 2), i});
        db[i]=1;
    }
    for (long long i=1; i<=k; i++) {
        long long a=q.top().second;
        q.pop(), db[a]++;
        q.push({p(t[a], db[a])-p(t[a], db[a]+1), a});
    }
    for (long long i=1; i<=n; i++) {
        long long s=t[i]/db[i], l=t[i]%db[i];
        sum+=p(t[i], db[i]);
    }
    cout << sum << "\n";
    return 0;
}