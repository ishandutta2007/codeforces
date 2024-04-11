#include <bits/stdc++.h>

using namespace std;
long long w, x, y, z, a, b, c, d, mini, sok=LONG_LONG_MAX;
vector<long long> p, s, k;
long long n(long long a, long long b) {
    return a*a+b*b-2*a*b;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        cin >> a >> b >> c;
        p.clear(), s.clear(), k.clear(), mini=sok, x=0, y=0, z=0;
        for (long long i=1; i<=a; i++) {
            cin >> d;
            p.push_back(d);
        }
        for (long long i=1; i<=b; i++) {
            cin >> d;
            s.push_back(d);
        }
        for (long long i=1; i<=c; i++) {
            cin >> d;
            k.push_back(d);
        }
        sort(p.begin(), p.end()), sort(s.begin(), s.end()), sort(k.begin(), k.end());
        while(x<a && y<b && z<c) {
            long long aa=p[x], bb=s[y], cc=k[z];
            bool f=true;
            while(f) {
                f=false;
                while(x+1<a && n(bb, p[x+1])+n(cc, p[x+1])<=n(bb, aa)+n(cc, aa)) x++, aa=p[x], f=1;
                while(y+1<b && n(aa, s[y+1])+n(cc, s[y+1])<=n(aa, bb)+n(cc, bb)) y++, bb=s[y], f=1;
                while(z+1<c && n(aa, k[z+1])+n(bb, k[z+1])<=n(aa, cc)+n(bb, cc)) z++, cc=k[z], f=1;
            }
            mini=min(mini, n(aa, bb)+n(aa, cc)+n(bb, cc));
            if (aa<=bb && aa<=cc) x++;
            else if (bb<=cc) y++;
            else z++;
        }
        cout << mini << "\n";
    }
    return 0;
}
//minden long long
/*
1 1 2 1
1 2 3 5

*/