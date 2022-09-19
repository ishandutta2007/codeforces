#include <bits/stdc++.h>

using namespace std;
long long sum, o[3], m[3], t[3];
int main()
{
    for (int i=0; i<3; i++) {
        cin >> t[i];
    }
    for (int i=0; i<3; i++) {
        m[i]=2e9;
        for (int j=0; j<t[i]; j++) {
            long long x; cin >>x;
            sum+=x, o[i]+=x;
            m[i]=min(m[i], x);
        }
    }
    cout << sum-2*min({o[0], o[1], o[2], m[0]+m[1], m[0]+m[2], m[1]+m[2]}) << "\n";
    return 0;
}