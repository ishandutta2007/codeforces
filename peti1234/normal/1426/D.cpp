#include <bits/stdc++.h>

using namespace std;
long long sum;
set<long long> sz;
int n, x, db;
int main()
{
    cin >> n;
    sz.insert(0);
    for (int i=1; i<=n; i++) {
        cin >> x, sum+=x;
        if (sz.find(sum)!=sz.end()) {
            db++;
            sz.clear(), sum=x;
            sz.insert(0);
        }
        sz.insert(sum);
    }
    cout << db << "\n";
    return 0;
}