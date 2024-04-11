#include <bits/stdc++.h>
 
using namespace std;
const int c=100005;
long long t[c], k[c], pr[c], sz[c], ossz=c-5, n, m, db, sum, sok=1e10+1;
long long h(long long a)
{
    long long ans=1;
    for (long long i=1; i<=m; i++) {
        ans*=a;
        if (ans>sok) {
            return -1;
        }
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (long long i=1; i<=n; i++) {
        long long x;
        cin >> x;
        t[x]++;
    }
    for (long long i=1; i<=ossz; i++) {
        k[i]=i;
    }
    for (long long i=2; i<=ossz; i++) {
        if (!pr[i]) {
            for (long long j=i; j<=ossz; j+=i) {
                pr[j]=true;
                while(k[j]%(i*i)==0) {
                    k[j]/=i;
                }
            }
        }
    }
    for (long long i=1;; i++) {
        long long x=h(i);
        if (x==-1) {
            db=i-1;
            break;
        }
        sz[i]=x;
    }
    for (int i=1; i<=ossz; i++) {
        for (int j=k[i]; j<=ossz; j+=k[i]) {
            long long y=sz[j]/i;
            if (j>db || y>ossz) {
                break;
            }
            if (i<=y && i*y==sz[j]) {
                if (i==y) {
                    sum+=t[i]*(t[i]-1)/2;
                } else {
                    sum+=t[i]*t[y];
                }
            }
        }
    }
    cout << sum << endl;
    return 0;
}