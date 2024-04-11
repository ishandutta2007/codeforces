#include <bits/stdc++.h>
 
using namespace std;
long long n;
vector<long long> p, q, r, s;
vector<pair<long long, long long> > poz, neg;
void out(long long a, long long b, long long c, long long d)
{
    cout.flush() << a << " " << b << " " << c << " " << d << "\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (long long i=3; i<=n; i++) {
        out(2, 1, 2, i);
        long long x, y;
        cin >> x;
        out(1, 1, 2, i);
        cin >> y;
        if (x>0) {
            poz.push_back({y, i});
        } else {
            neg.push_back({y, i});
        }
    }
    sort(poz.begin(), poz.end());
    sort(neg.begin(), neg.end());
    long long a=poz.size(), b=neg.size();
    for (long long i=0; i<b-1; i++) {
        long long x;
        long long se=neg[i].second;
        out(2, 1, se, neg[i+1].second);
        cin >> x;
        if (x==1) {
            p.push_back(se);
        } else {
            q.push_back(se);
        }
    }
    if (b>0) {
        p.push_back(neg[b-1].second);
    }
    for (long long i=0; i<a-1; i++) {
        long long x;
        long long se=poz[i].second;
        out(2, 1, se, poz[i+1].second);
        cin >> x;
        if (x==1) {
            r.push_back(se);
        } else {
            s.push_back(se);
        }
    }
    if (a>0) {
        r.push_back(poz[a-1].second);
    }
    cout << 0 << " " << 1 << " ";
    for (long long i=0; i<p.size(); i++) {
        cout << p[i] << " ";
    }
    a=q.size(), b=s.size();
    for (long long i=a-1; i>=0; i--) {
        cout << q[i] << " ";
    }
    cout << 2 << " ";
    for (long long i=0; i<r.size(); i++) {
        cout << r[i] << " ";
    }
    for (long long i=b-1; i>=0; i--) {
        cout << s[i] << " ";
    }
    cout.flush() << "\n";
    return 0;
}