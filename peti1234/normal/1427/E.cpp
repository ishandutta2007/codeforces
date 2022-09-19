#include <bits/stdc++.h>

using namespace std;
const long long c=1000;
long long n, ert, si, maxi=2e17, e=1;
vector<long long> sol;
void pb(long long a) {
    sol.push_back(a);
}
void add(long long a, long long s) {
    long long sum=0;
    for (long long i=0; i<60; i++) {
        if (a&(e<<i)) pb(1), pb(s*sum), pb(s*(e<<i)), sum+=(e<<i);
    }
}
void po(long long n) {
    for (int i=0; i<60; i++) {
        if (maxi/(e<<i)>n) {
            pb(1), pb(n*(e<<i)), pb(n*(e<<i));
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false), cout.tie(0);
    cin >> n;
    pb(2), pb(n), pb(n);
    po(n);
    for (long long i=1; i<=c; i++) {
        for (long long j=i; j<=1000*c; j++) {
            long long x=(n*i)^(n*j), y=x%n;
            if (y && (n-1)%y==0) {
                add(i, n), add(j, n);
                pb(2), pb(n*i), pb(n*j);
                po(x), add((n-1)/y, x);
                ert=x*(n-1)/y;
                i=c;
                break;
            }
        }
    }
    if (ert%2==1) {
        pb(1), pb(ert), pb(n);
        ert+=n;
    }
    add((ert+1)/n, n);
    pb(2), pb(ert), pb(ert+1);
    si=sol.size();
    cout << si/3 << "\n";
    for (int i=0; i<si; i+=3) {
        cout << sol[i+1] << " ";
        if (sol[i]==1) cout << "+ ";
        else cout << "^ ";
        cout << sol[i+2] << " ";
        cout << "\n";
    }
    return 0;
}