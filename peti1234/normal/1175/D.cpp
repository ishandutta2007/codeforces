#include <bits/stdc++.h>
 
using namespace std;
long long sum=0;
vector<long long> p;
long long n, k;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    for (int i=1; i<=n; i++) {
        int a;
        cin >> a;
        sum+=a;
        p.push_back(sum);
    }
    p.pop_back();
    for (int i=0; i<n; i++) {
        p[i]=sum-p[i];
        //cout << p[i] << endl;
    }
    sort(p.rbegin(), p.rend());
    for (int i=0; i<k-1; i++) {
        sum+=p[i];
    }
    cout << sum << endl;
    return 0;
}