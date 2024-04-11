#include <bits/stdc++.h>

using namespace std;
const int c=1000005;
long long n, pref[c], pref2[c], pos, mini=1e15;
void add(int l, int r, int kezd, int dif) {
    //cout << "add " << l << " " << r << " " << kezd << " " << dif << "\n";
    // l-tl r-ig kezd, kezd+dif, kezd+2*dif.....
    pref[l]+=kezd, pref[r+1]-=kezd;
    pref2[l+1]+=dif;
    pref2[r+1]-=dif;
    pref[r+1]-=dif*(r-l);
}
int main()
{
    cin >> n;
    for (int i=1; i<=n; i++) {
        int x;
        cin >> x;
        if (x>i) {
            add(0, x-i, x-i, -1);
            add(x-i, n-i, 0, 1);
            add(n-i+1, n-1, x-1, -1);
        } else {
            add(0, n-i, i-x, 1);
            add(n-i+1, n+x-i, x-1, -1);
            add(n+x-i, n-1, 0, 1);
        }
    }
    for (int i=1; i<n; i++) {
        pref[i]+=pref[i-1];
        pref2[i]+=pref2[i-1];
    }
    for (int i=1; i<n; i++) {
        pref2[i]+=pref2[i-1];
    }
    for (int i=0; i<n; i++) {
        long long ert=pref[i]+pref2[i];
        if (ert<mini) {
            mini=ert, pos=i;
        }
    }
    cout << mini << " " << pos << "\n";
    return 0;
}
/*
3
2 3 1
*/