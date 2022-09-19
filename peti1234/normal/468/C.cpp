#include <bits/stdc++.h>

using namespace std;
long long ert, ert2, lo=1, hi=20000000000000004, mid;
long long ossz(long long s) {
    long long ans=0;
    while (s) {
        ans+=s%10;
        s/=10;
    }
    return ans;
}
long long sum(long long s) {
    if (!s) {
        return 0;
    }
    long long ans=0;
    while (s%10) {
        ans+=ossz(s);
        s--;
    }
    return ossz(s)+ans+45*(s/10)+10*sum((s-1)/10);
}
int main()
{
    cin >> ert;
    while (hi-lo>1) {
        mid=(hi+lo)/2;
        if (sum(mid)<=ert) {
            lo=mid;
        } else {
            hi=mid;
        }
    }
    ert2=sum(lo), hi=lo, lo=1;
    while (ert2!=ert) {
        if (ert2>ert) {
            ert2-=ossz(lo);
            lo++;
        } else {
            hi++;
            ert2+=ossz(hi);
        }
    }
    cout << lo << " " << hi << "\n";
    return 0;
}