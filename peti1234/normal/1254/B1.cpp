#include <bits/stdc++.h>

using namespace std;
const long long c=1000005, sok=1e18;
long long n, t[c], sum, mini=sok, pr[c], k=c-1;
long long ker(long long a) {
    long long ans=0, x=0, db=0;
    for (long long i=1; i<=n; i++) {
        long long f=t[i];
        long long r=a/2;
        long long q=min(f, a-db);
        if (db>r) {
            f-=q;
            ans+=q*(i-x);
            db+=q;
        }
        f%=a
        ;
        db%=a;
        if (db<=r && (db+f)%a>r) {
            x=i;
        }
        db+=f;
        db%=a;
        if (db<=r) {
            ans+=db;
        }
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    for (long long i=2; i<=k; i++) {
        if (!pr[i]) {
            for (long long j=2*i; j<=k; j+=i) {
                pr[j]=true;
            }
        }
    }
    cin >> n;
    for (long long i=1; i<=n; i++) {
        cin >> t[i];
        sum+=t[i];
    }
    for (long long i=2; i*i<=sum; i++) {
        if (sum%i==0 && !pr[i]) {
            while(sum%i==0) {
                sum/=i;
            }
            mini=min(mini, ker(i));
        }
    }
    if (sum>1) {
        mini=min(mini, ker(sum));
    }
    if (mini==sok) {
        mini=-1;
    }
    cout << mini << "\n";
    return 0;
}