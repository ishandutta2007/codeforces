#include <bits/stdc++.h>

using namespace std;
const int c=52;
int w;
long long n, k, fakt[c], db[c];
int ans[c], jo[c], cel[c];
void calc(int kezd, int veg, long long s) {
    for (int i=kezd; i<=veg; i++) {
        jo[i]=0, cel[i]=i;
    }
    ans[kezd]=veg, jo[veg]=1, cel[kezd]=veg;
    for (int i=kezd+1; i<=veg; i++) {
        int rem=veg-i-1;
        for (int j=kezd; j<=veg; j++) {
            if (i==veg && ! jo[j]) {
                ans[i]=j;
            }
            if (jo[j] || cel[j]==i) {
                continue;
            }
            if (k<=fakt[rem]*s) {
                ans[i]=j;
                jo[j]=1;
                cel[i]=cel[j];
                for (int i=kezd; i<=veg; i++) {
                    cel[i]=cel[cel[i]];
                }
                break;
            }
            k-=fakt[rem]*s;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    fakt[0]=1, db[0]=1;
    for (int i=1; i<=21; i++) {
        if (i!=21) {
            fakt[i]=fakt[i-1]*i;
        }
        db[i]+=db[i-1];
        for (int j=2; j<=i; j++) {
            db[i]+=fakt[j-2]*db[i-j];
        }
    }
    cin >> w;
    for (int tc=1; tc<=w; tc++) {
        cin >> n >> k;
        if (n<22 && db[n]<k) {
            cout << -1 << "\n";
            continue;
        }
        int pos=1;
        while (n-pos>=22) {
            ans[pos]=pos;
            pos++;
        }
        while (pos<=n) {
            if (db[n-pos]>=k) {
                ans[pos]=pos;
                pos++;
                continue;
            }
            k-=db[n-pos];
            for (int i=1; ; i++) {
                long long s=db[n-pos-i];
                if (fakt[i-1]*s>=k) {
                    calc(pos, pos+i, s);
                    pos+=i+1;
                    break;
                }
                k-=fakt[i-1]*s;
            }
        }
        for (int i=1; i<=n; i++) {
            cout << ans[i] << " ";
        }
        cout << "\n";

    }
    return 0;
}