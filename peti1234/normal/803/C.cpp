#include <bits/stdc++.h>

using namespace std;
long long n, k;
long long m;
long long maxi;
long long x;
vector<long long> p;
int main()
{
    cin >> n >> k;
    for (long long i=1; i<=sqrt(n); i++) {
        if (n%i==0) {
            p.push_back(i);
            p.push_back(n/i);
        }
    }
    sort (p.begin(), p.end());
    if (k>1000000) {
        cout << -1 << endl;
        return 0;
    }
    m=(k*(k+1))/2;
    if (m>n) {
        cout << -1 << endl;
        return 0;
    }
    x=n/m;
    x++;
    for (long long i=0; i<p.size(); i++) {
        if (p[i]<=x && (m*p[i]<=n)) {
            maxi=p[i];
        }
    }

    for (long long i=1; i<k; i++) {
        cout << i*maxi << " ";
        n-=i*maxi;
    }
    cout << n << endl;
    return 0;
}