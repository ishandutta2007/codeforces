#include <bits/stdc++.h>

using namespace std;
long long n, si, t[100005];
vector<long long> sz;
long long calc() {
    long long ans=0;
    for (auto a:sz) {
        for (auto b:sz) {
            if (a<b) ans=__gcd(ans, t[a]*t[b]);
        }
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
        if (i<=2) sz.push_back(i);
        else {
            long long kezd=calc();
            sz.push_back(i);
            if (calc()==kezd) {
                sz.pop_back();
            }
        }
    }
    si=sz.size();
    for (int i=0; i<si; i++) {
        long long kezd=calc(), x=sz.back();
        sz.pop_back();
        if (calc()!=kezd) {
            sz.push_back(x);
        }
        rotate(sz.begin(), sz.begin()+1, sz.end());
    }
    si=sz.size();
    int sum=0;
    for (int i=1; i<(1<<si); i++) {
        sum+=abs(__builtin_popcount(i)-2);
    }
    cout << sum << "\n";
    for (int i=1; i<(1<<si); i++) {
        int pc=__builtin_popcount(i), db=(pc%2 ? 2-pc : pc-2);
        for (int k=1; k<=abs(db); k++) {
            cout << (db<0) << " " << pc << " ";
            for (int j=0; j<si; j++) {
                if (i & (1<<j)) {
                    cout << sz[j] << " ";
                }
            }
            cout << "\n";
        }
    }
    return 0;
}