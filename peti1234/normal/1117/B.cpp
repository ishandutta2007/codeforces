#include <bits/stdc++.h>

using namespace std;
long long n, m, k;
long long fi, se;
long long s, t;
long long sum;
int main()
{
    cin >> n >> m >> k;
    for (int i=1; i<=n; i++) {
        long long x;
        cin >> x;
        se=max(se, x);
        if (se>fi) {
            swap(fi, se);
        }
    }
    s=m/(k+1);
    t=m%(k+1);
    sum=s*(k*fi+se);
    sum+=t*fi;
    cout << sum << endl;
    return 0;
}