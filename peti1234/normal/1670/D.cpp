#include <bits/stdc++.h>

using namespace std;
const int c=100005;
long long w, ert[c];
int main()
{
    ios_base::sync_with_stdio(false);
    for (int i=1; i<c; i++) {
        long long a=i/3, b=i/3, c=i/3;
        if (i%3>1) b++;
        if (i%3>0) a++;
        ert[i]=(a*b+a*c+b*c)*2;
    }
    cin >> w;
    while (w--) {
        long long x;
        cin >> x;
        int lo=1, hi=c, mid;
        while (hi-lo>1) {
            mid=(hi+lo)/2;
            if (ert[mid]>=x) hi=mid;
            else lo=mid;
        }
        cout << hi << "\n";

    }
    return 0;
}