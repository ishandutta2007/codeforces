#include <bits/stdc++.h>

using namespace std;
long long n, k;
vector<long long> v[100001];
long long x, y=0;
long long sz=2;
long long e=1;
bool ker(long long p) {
    long long c=n;
    long long d=1;
    long long e=1;
    long long sum=0;
    while(c>0) {
        sum+=min(e, c)*d;
        c-=e;
        d++;
        e*=p;
    }
    return sum<=k;
}
int main()
{
    cin >> n >> k;
    if (n*(n+1)/2<k || k<2*n-1) {
        cout << "No";
        return 0;
    }
    x=n;
    while(x-y>1) {
        long long p=(x+y)/2;
        if (ker(p)) {
            x=p;
        } else {
            y=p;
        }
    }
    cout << "Yes" << endl;
    v[1].push_back(1);
    k--;
    for (long long i=2; i<=n; i++) {
        if (v[sz].size()<e*x && (sz+sz+n-i)*(n-i+1)/2>=k) {
            v[sz].push_back(i);
            k-=sz;
        } else {
            e=v[sz].size();
            sz++;
            v[sz].push_back(i);
            k-=sz;
        }
    }
    for (int i=2; i<=n; i++) {
        for (int j=0; j<v[i].size(); j++) {
            cout << v[i-1][j/x] << " ";
        }
    }
    return 0;
}