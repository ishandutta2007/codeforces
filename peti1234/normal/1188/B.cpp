#include <bits/stdc++.h>

using namespace std;
long long db=0;
vector<long long> v;
long long n, p, k;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> p >> k;
    for (int i=1; i<=n; i++) {
        long long a;
        cin >> a;
        long long b=-a*k;
        a=a*a%p*a%p*a%p;
        v.push_back((b+a+p*p)%p);
    }
    sort(v.begin(), v.end());
    for (int i=0; i<n; ) {
        int k=i;
        while(k<n && v[k]==v[i]) {
            k++;
        }
        db+=(k-i)*(k-i-1)/2;
        i=k;
    }
    cout << db << endl;
    return 0;
}