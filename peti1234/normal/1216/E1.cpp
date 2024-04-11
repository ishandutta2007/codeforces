#include <bits/stdc++.h>

using namespace std;
const int c=11;
long long kis[c], db[c];
long long dig(long long x) {
    int cnt=0;
    while (x) {
        x/=10;
        cnt++;
    }
    return cnt;
}
long long a2(long long x) {
    return (x*(x+1))/2;
}
long long calc(long long ert) {
    if (!ert) {
        return 0;
    }
    long long sum=0;
    int s=dig(ert);
    for (int i=1; i<s; i++) {
        sum+=a2(db[i])*i+(ert-kis[i+1]+1)*db[i]*i;
    }
    sum+=s*a2(ert-kis[s]+1);
    return sum;
}
int main()
{
    ios_base::sync_with_stdio(false);
    kis[1]=1, db[1]=9;
    for (int i=2; i<c; i++) {
        kis[i]=kis[i-1]*10;
        db[i]=db[i-1]*10;
    }
    int q;
    cin >> q;
    while (q--) {
        long long ert;
        cin >> ert;

        long long lo=0, hi=1e9, mid;
        while (hi-lo>1) {
            mid=(hi+lo)/2;
            if (calc(mid)<ert) {
                lo=mid;
            } else {
                hi=mid;
            }
        }
        ert-=calc(lo);
        long long val=0;
        for (int i=1; i<c; i++) {
            if (db[i]*i<ert) {
                ert-=db[i]*i;
            } else {
                long long s=(ert-1)/i;
                val=kis[i]+s;
                ert-=s*i;
                break;
            }
        }
        int s=dig(val);
        while (s>ert) {
            val/=10;
            s--;
        }
        cout << val%10 << "\n";
    }
    return 0;
}