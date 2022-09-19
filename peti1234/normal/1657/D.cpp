#include <bits/stdc++.h>

using namespace std;
long long n, k, q, maxi[1000005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    for (int i=1; i<=n; i++) {
        long long a, b, c;
        cin >> a >> b >> c;
        maxi[a]=max(maxi[a], b*c);
    }
    for (int i=1; i<=k; i++) {
        for (int j=2*i; j<=k; j+=i) {
            maxi[j]=max(maxi[j], maxi[i]*(j/i));
        }
        maxi[i]=max(maxi[i], maxi[i-1]);
    }
    cin >> q;
    while (q--) {
        long long a, b, p;
        cin >> a >> b;
        p=a*b;
        if (maxi[k]<=p) cout << -1 << " ";
        else {
            int lo=0, hi=k, mid;
            while (hi-lo>1) {
                mid=(hi+lo)/2;
                if (maxi[mid]>p) hi=mid;
                else lo=mid;
            }
            //cout << "valasz ";
            cout << hi << " ";
        }
    }
    return 0;
}