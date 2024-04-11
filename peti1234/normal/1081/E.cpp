#include <bits/stdc++.h>

using namespace std;
long long sum, n, p=1, x;
vector<long long> sol;
bool tn(long long a) {
    long long x=sqrt(a);
    return x*x==a;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (long long i=1; i<=n/2; i++) {
        cin >> x;
        while(sum>=p*p) p++;
        bool fix=0;
        while(!fix) {
            if (tn(p*p+x)) sol.push_back(p*p-sum), sol.push_back(x), sum=p*p+x, fix=true;
            if (p>200000) {
                cout << "No" << "\n";
                return 0;
            }
            p++;
        }
    }
    cout << "Yes" << "\n";
    for (long long i=0; i<n; i++) cout << sol[i] << " ";
    return 0;
}
// minden ll;