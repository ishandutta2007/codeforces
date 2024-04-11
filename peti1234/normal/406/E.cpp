#include <bits/stdc++.h>

using namespace std;
long long sum, m, n, kx, nx, sa, sb, q1, q2;
vector<int> a, b;
bool sp;
long long p(long long x, long long y) {
    if (y==2) return x*(x-1)/2;
    return x*(x-1)*(x-2)/6;
}
int main()
{
    cin >> m >> n;
    for (int i=1; i<=n; i++) {
        int x, y;
        cin >> x >> y;
        if (x==0) a.push_back(y);
        else b.push_back(y);
    }
    sa=a.size(), sb=b.size();
    sort(a.begin(), a.end()), sort(b.begin(), b.end());
    if (!sa) for (int i=0; i<sb; i++) q1+=(b[i]==b[0]), q2+=(b[i]==b[sb-1]);
    else if (!sb) for (int i=0; i<sa; i++) q1+=(a[i]==a[0]), q2+=(a[i]==a[sa-1]);
    else if (a[0]>b[sb-1]) {
        for (int i=0; i<sa; i++) q1+=(a[i]==a[0]);
        for (int i=0; i<sb; i++) q2+=(b[i]==b[sb-1]);
    } else if (b[0]>a[sa-1]) {
        for (int i=0; i<sa; i++) q2+=(a[i]==a[sa-1]);
        for (int i=0; i<sb; i++) q1+=(b[i]==b[0]);
    }
    if (q1) {
        sum=q1*(q1+q2-2)*(q2)/2+q1*q2*(n-q1-q2);
        if (q1==n) sum=p(n, 3);
    } else {
        sum=p(n, 3)-p(sa, 3)-p(sb, 3);
        for (int i=0; i<sa; i++) {
            while(kx<sb && b[kx]<a[i]) kx++;
            while(nx<sb && b[nx]<=a[i]) nx++;
            sum-=p(kx, 2), sum-=p(sb-nx, 2);
        }
        kx=0, nx=0;
        for (int i=0; i<sb; i++) {
            while(kx<sa && a[kx]<b[i]) kx++;
            while(nx<sa && a[nx]<=b[i]) nx++;
            sum-=p(kx, 2), sum-=p(sa-nx, 2);
        }
    }
    cout << sum << "\n";
    return 0;
}