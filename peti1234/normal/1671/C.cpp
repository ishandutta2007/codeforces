#include <bits/stdc++.h>

using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    int w;
    cin >> w;
    while (w--) {
        vector<long long> sz;
        long long n, p, d=0, sum=0;
        cin >> n >> p;
        for (int i=0; i<n; i++) {
            int x;
            cin >> x;
            sz.push_back(x);
        }
        sort(sz.begin(), sz.end());
        for (int i=1; i<n; i++) {
            sz[i]+=sz[i-1];
        }
        for (int i=n-1; i>=0; i--) {
            if (sz[i]+d*(i+1)<=p) {
                long long kov=(p-sz[i])/(i+1)+1;
                sum+=(kov-d)*(i+1);
                d=kov;
            }
        }
        cout << sum << "\n";
    }
    return 0;
}
/*
1
3 7
2 1 2
*/