#include <bits/stdc++.h>

using namespace std;
int w, n;
multiset<long long> a, b;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n;
        long long sum=0;
        for (int i=1; i<=n; i++) {
            int x;
            cin >> x;
            a.insert(x);
            sum+=x;
        }
        b.insert(sum);
        bool baj=0;
        int l=0;
        while (l<n-1) {
            auto x=b.begin();
            long long s=*x;
            b.erase(x);
            if (a.find(s)!=a.end()) {
                a.erase(a.find(s));
            } else {
                b.insert(s/2);
                b.insert((s+1)/2);
                l++;
            }
        }
        cout << (a==b ? "YES" : "NO") << "\n";

        a.clear(), b.clear();
    }
    return 0;
}