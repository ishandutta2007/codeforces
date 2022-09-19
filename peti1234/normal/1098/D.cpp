#include <bits/stdc++.h>
// int x=*s[i].begin();
using namespace std;
multiset <long long> s[33];
long long sum[33];
long long f;
int q;
int main ()
{
    ios_base::sync_with_stdio(false);
    cin >> q;
    for (int i=1; i<=q; i++) {
        char c;
        cin >> c;
        long long x;
        cin >> x;
        int e=0;
        long long y=x;
        while(y>0) {
            y/=2;
            e++;
        }
        if (c=='-') {
            auto itr = s[e].find(x);
            if(itr!= s[e].end()){
                s[e].erase(itr);
            }
            f--;
            x*=-1;

        } else {
            s[e].insert(x);
            f++;
        }
        sum[e]+=x;
        long long g=0;
        long long d=0;
        for (int i=1; i<=31; i++) {
            if (s[i].size()!=0) {
                long long y=*s[i].begin();
                if (g*2<y) {
                    d++;
                }
            }
            g+=sum[i];
        }
        cout << f-d << endl;
    }
    return 0;
}