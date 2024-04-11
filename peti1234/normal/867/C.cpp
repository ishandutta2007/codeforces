#include <bits/stdc++.h>

using namespace std;
long long n, k;
long long he, hm;
long long c, d;
long long p;
long long sze, szm;
vector<pair<long long, long long> > e;
vector<pair<long long, long long> > m;
int main()
{
    cin >> n >> k;
    for (long long i=1; i<=n; i++) {
        long long a, b, c;
        cin >> a >> b >> c;
        p+=a*min(b, c);
        if (b>c) {
            e.push_back({b-c, a});
            he+=a;
        } else {
            m.push_back({c-b, a});
            hm+=a;
        }
    }

    sort(e.begin(), e.end());
    reverse(e.begin(), e.end());
    sort(m.begin(), m.end());
    reverse(m.begin(), m.end());
    c=(he/k)*k;
    d=(hm/k)*k;
    long long aa=0;
    for (long long l=0; l<e.size(); l++) {
    if (c>0) {
        if (c>=e[l].second) {
            p+=e[l].first*e[l].second;
            c-=e[l].second;
            e[l].second=0;
        } else {
            p+=e[l].first*c;
            e[l].second-=c;
            c=0;
        }
    }
    if (c==0) {
        sze+=e[l].first*e[l].second;
        aa+=e[l].second;
    }
    }
    for (long long l=0; l<m.size(); l++) {
    if (d>0) {
        if (d>=m[l].second) {
            p+=m[l].first*m[l].second;
            d-=m[l].second;
            m[l].second=0;
        } else {
            p+=m[l].first*d;
            m[l].second-=d;
            d=0;
        }
    }
    if (d==0) {
        szm+=m[l].first*m[l].second;
        aa+=m[l].second;
    }
    }
    if (aa<=k) {
        p+=max(sze, szm);
    } else {
        p+=sze;
        p+=szm;
    }
    cout << p << endl;
    return 0;
}