#include <bits/stdc++.h>

using namespace std;

int main()
{
    int w;
    cin >> w;
    while (w--) {
        long long n, mini=1e7, maxi=0, ans;
        set<long long> s;
        cin >> n;
        for (int i=1; i<=n; i++) {
            long long x;
            cin >> x;
            mini=min(mini, x);
            maxi=max(maxi, x);
            s.insert(x);
        }
        ans=mini*maxi;
        s.insert(1), s.insert(ans);
        int cnt=0;
        bool jo=1;
        for (long long i=1; i*i<=ans; i++) {
            if (ans%i==0) {
                cnt++;
                if (s.find(i)==s.end()) {
                    jo=0;
                }
                if (ans/i!=i) {
                    if (s.find(ans/i)==s.end()) {
                        jo=0;
                    }
                    cnt++;
                }
            }
        }
        if (cnt!=n+2) jo=0;
        cout << (jo ? ans : -1) << "\n";
    }
    return 0;
}
/*
1
1
2
*/