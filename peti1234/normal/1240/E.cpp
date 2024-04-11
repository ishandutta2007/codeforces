#include <bits/stdc++.h>

using namespace std;
const int c=500005;
long long n, db[c], ans, maxi, m2, o=0;
int s(int a, int b) {
    if (a>b) {
        return 0;
    }
    return (db[b]-db[max(a-1, 0)]);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=n; i++) {
        int x;
        cin >> x;
        db[x]++;
        if (x>m2) {
            m2=x;
        }
        if (m2>maxi) {
            swap(maxi, m2);
        }
    }
    for (int i=1; i<=maxi; i++) {
        db[i]+=db[i-1];
    }
    for (long long len=2; len<=maxi; len++) {
        long long cnt=0;
        for (int i=len; i<=maxi; i+=len) {
            cnt+=(i/len-1)*s(i-len, i-1);
        }
        long long ut=maxi-maxi%len;
        cnt+=maxi/len*s(ut, maxi);
        long long lo=0, hi=maxi, mid, val;
        while (hi-lo>1) {
            mid=(hi+lo)/2;
            if (maxi>=2*mid && cnt-maxi/len+(maxi-2*mid)/len>=mid || m2>=mid && cnt-maxi/len+(maxi-mid)/len-m2/len+(m2-mid)/len>=mid) {
                lo=mid;
            } else {
                hi=mid;
            }
        }
        if (lo>1) {
            ans=max(ans, len*lo);
        }
        val=lo;
        while (val<lo+2) {
            val++;
            long long rem=val%len, kul=cnt-val-val/len*2;
            if (val>m2 && 2*val>maxi) {
                break;
            }
            int k=0, e=0;
            for (int i=len; i<=maxi; i+=len) {
                if (i>val) {
                    k+=s(i-len+rem, i-1);
                }
                if (i>2*val) {
                    e+=s(i-len+2*rem%len, i-1);
                }
            }
            if (maxi>=val) {
                k+=s(ut+rem, maxi);
            }
            if (maxi>=2*val) {
                e+=s(ut+2*rem%len, maxi);
            }
            k=min(k, 2), e=min(e, 1);
            if (kul-2+k>=0 || kul-1+e-(2*rem>=len)>=0) {
                ans=max(ans, len*val);
            }
        }
    }
    cout << ans << "\n";
    return 0;
}