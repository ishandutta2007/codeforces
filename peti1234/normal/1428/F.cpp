#include <bits/stdc++.h>

using namespace std;
const long long c=500002;
vector<pair<long long, long long> > sz;
long long n, kom[c], sum, si;
string s;
void add(long long a, long long b) {
    si=sz.size();
    sz.push_back({a, b});
    if (si) {
        kom[si]=kom[si-1]+a*b;
    }
}
int main()
{
    cin >> n >> s;
    add(c, 0);
    for (long long i=0; i<n; i++) {
        if (s[i]=='0') {
            if (sz.back().first) add(0, 0);
            sz.back().second++;
            si=sz.size();
            sum+=kom[si-1];
        } else {
            long long db=1, tsz=0;
            while(i<n-1 && s[i+1]=='1') db++, i++;
            while(db>sz.back().first) {
                long long ert=sz.back().first, cnt=sz.back().second;
                sz.pop_back(), si--;
                tsz+=cnt;
                sum+=ert*cnt*db;
                sum+=cnt*(db-ert)*(db-ert+1)/2;
            }
            sum+=db*(db+1)*(db+2)/6;
            si=sz.size();
            sum+=kom[si-1]*db;
            add(db, tsz+1);
            for (long long i=db-1; i; i--) add(i, 1);
        }
    }
    cout << sum << "\n";
    return 0;
}