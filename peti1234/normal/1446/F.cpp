#include <bits/stdc++.h>

using namespace std;
const int c=200002;
int w,  kezd[c], veg[c], t[c];
long long sum, n, k;
vector<pair<long double, int> > sz;
long double x[c], y[c], lo=0, hi=2e4, mid, eps=1e-7;
void pb(long double a, long double b, int i) {
    if (b<0) {
        a=c-a;
    }
    sz.push_back({a, i});
}
int lsb(int a) {
    return (a & (-a));
}
void add(int a, int b) {
    while (a<c) {
        t[a]+=b;
        a+=lsb(a);
    }
}
int ask(int a) {
    int sum=0;
    while (a) {
        sum+=t[a];
        a-=lsb(a);
    }
    return sum;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    k=n*(n-1)/2-k;
    for (int i=1; i<=n; i++) {
        cin >> x[i] >> y[i];
    }
    while (hi-lo>eps) {
        mid=(hi+lo)/2;
        sum=0;
        sz.clear();
        for (int i=1; i<=n; i++) {
            long double dist=sqrt((x[i]*x[i]+y[i]*y[i]));
            if (dist>mid) {
                long double r=(sqrt(dist*dist-mid*mid)), p=(mid*mid)/(mid*mid+r*r), ert=sqrt(mid*mid/dist/dist-p*p);
                long double xx=p*x[i], yy=p*y[i], v1=ert*y[i], v2=ert*x[i];
                pb(xx+v1, yy-v2, i);
                pb(xx-v1, yy+v2, i);
            }
        }
        for (int i=1; i<=n; i++) {
            kezd[i]=veg[i]=0;
        }
        sort(sz.begin(), sz.end());
        int si=sz.size();
        for (int i=0; i<si; i++) {
            int id=sz[i].second;
            if (!kezd[id]) {
                kezd[id]=i+1;
            } else {
                veg[id]=i+1;
            }
        }
        for (int i=0; i<si; i++) {
            int id=sz[i].second;
            if (kezd[id]==i+1) {
                sum+=ask(veg[id]);
                add(veg[id], 1);
            } else {
                add(veg[id], -1);
            }
        }
        if (sum>k) {
            lo=mid;
        } else {
            hi=mid;
        }
    }

    cout.precision(10);
    cout << lo << "\n";
    return 0;
}