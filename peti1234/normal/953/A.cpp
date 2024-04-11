#include <bits/stdc++.h>

using namespace std;
vector<long long> a;
vector<long long> b;
vector<long long> c;
long long sok=2000000000;
int main()
{
    long long l, r;
    cin >> l >> r;
    a.push_back(1);
    b.push_back(1);
    while(a.back()<=sok) {
        a.push_back(a.back()*2);
    }
    while(b.back()<=sok) {
        b.push_back(b.back()*3);
    }
    /*for (int i=0; i<b.size(); i++) {
        cout << b[i] << endl;
    }*/
    for (long long i=0; i<a.size(); i++) {
        for (long long j=0; j<b.size(); j++) {
            long long x=a[i];
            long long y=b[j];
            c.push_back(x*y);
        }
    }
    int v=0;
    sort(c.begin(), c.end());
    for (int i=0; i<c.size(); i++) {
        long long x=c[i];
        if (x>=l && x<=r) {
            v++;
        }
    }
    cout << v << endl;
    return 0;
}