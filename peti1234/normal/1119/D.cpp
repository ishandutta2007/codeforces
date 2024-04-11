#include <bits/stdc++.h>

using namespace std;
long long n;
long long t[100001];
long long kom[100001];
vector<long long> d;
long long q;
long long ker(long long x)
{
    long long a=0, b=n;
    while(b-a>1) {
        long long c=(a+b)/2;
        if (d[c]<=x) {
            a=c;
        } else {
            b=c;
        }
    }
    return a;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (long long i=1; i<=n; i++) {
        cin >> t[i];
    }
    sort(t+1, t+n+1);
    for (long long i=2; i<=n; i++) {
        d.push_back(t[i]-t[i-1]);
    }
    d.push_back(0);
    sort(d.begin(), d.end());
    for (long long i=1; i<n; i++) {
        kom[i]=kom[i-1]+d[i];
    }
    /*for (int i=1; i<n; i++) {
        cout << d[i] << " ";
    }
    cout << endl;
    for (int i=1; i<n; i++) {
        cout << kom[i] << " ";
    }*/
    cin >> q;
    for (long long i=1; i<=q; i++) {
        long long a, b;
        cin >> a >> b;
        long long x=ker(b-a);
        //cout << x << endl;
        cout << (b-a+1)*(n-x)+kom[x] << endl;
    }
    return 0;
}