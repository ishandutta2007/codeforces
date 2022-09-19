#include <bits/stdc++.h>

using namespace std;
long long t[2001];
long long k[2001];
long long sa[2001];
long long sb[2001];
long long a, b;
long long p;
int main()
{
    cin >> a >> b;
    for (int i=1; i<=a; i++) {
        int x;
        cin >> x;
        t[i]=t[i-1]+x;
    }
    for (int i=1; i<=b; i++) {
        int x;
        cin >> x;
        k[i]=k[i-1]+x;
    }
    for (int i=1; i<=max(a, b); i++) {
        sa[i]=INT_MAX;
        sb[i]=INT_MAX;
    }
    for (int i=0; i<a; i++) {
        for (int j=i+1; j<=a; j++) {
            sa[j-i]=min(sa[j-i], t[j]-t[i]);
        }
    }
    for (int i=0; i<b; i++) {
        for (int j=i+1; j<=b; j++) {
            sb[j-i]=min(sb[j-i], k[j]-k[i]);
        }
    }
    cin >> p;
    int maxi=0;
    for (int i=1; i<=a; i++) {
        for (int j=1; j<=b; j++) {
            if (sa[i]*sb[j]<=p) {
                maxi=max(maxi, i*j);
            }
        }
    }
    cout << maxi << endl;
    return 0;
}