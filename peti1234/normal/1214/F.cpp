#include <bits/stdc++.h>

using namespace std;
const int c=200002;
vector<pair<int, int> > a, b;
long long sol[c], n, m, lo, hi, mid, ans, pos;
long long add(int i, int j, int k) {
    sol[a[i].second]=b[j].second;
    return abs(a[i].first+k-b[j].first);
}
long long ch(int xx) {
    long long sum=0, x=abs(xx);
    for (int i=0; i<x; i++) {
        if (xx>0) sum+=add(i, n-i-1, m);
        else sum+=add(n-i-1, i, -m);
    }
    for (int i=x; i<n; i++) {
        if (xx>0) sum+=add(i, i-x, 0);
        else sum+=add(i-x, i, 0);
    }
    if (sum<ans) ans=sum, pos=xx;
    return sum;
}
int main()
{
    cin >> m >> n, ans=n*m, hi=n, lo=-n;
    for (int i=1; i<=n; i++) {
        int x; cin >> x;
        a.push_back({x, i});
    }
    for (int i=1; i<=n; i++) {
        int x; cin >> x;
        b.push_back({x, i});
    }
    sort(a.begin(), a.end()), sort(b.begin(), b.end());
    ch(-n), ch(n);
    while(hi-lo>1) {
        mid=(hi+lo)/2;
        long long x=ch(mid), y=ch(mid+1);
        if (x>y) lo=mid;
        else hi=mid;
    }
    ch(pos);
    cout << ans << "\n";
    for (int i=1; i<=n; i++) {
        cout << sol[i] << " ";
    }
    cout << "\n";
    return 0;
}