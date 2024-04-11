#include <bits/stdc++.h>

using namespace std;
long long n;
vector<long long> sol;
void pb(long long i) {
    sol.push_back(i+n/i*(i)*(i-1)/2);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (long long i=1; i*i<=n; i++) {
        if (n%i==0) {
            pb(i);
            if (i*i!=n) {
                pb(n/i);
            }
        }
    }
    sort(sol.begin(), sol.end());
    for (long long i:sol) cout << i << " ";
    cout << "\n";
    return 0;
}