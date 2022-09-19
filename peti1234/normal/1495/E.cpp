#include <bits/stdc++.h>

using namespace std;
const int c=5000005;
long long n, m, a[c], ans[c], sum, s0, s1, mod=1e9+7;
long long ut, seed, base;
bool t[c];
long long rnd() {
    long long ret=seed;
	seed=(seed*base+233)%mod;
	return ret;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    cin >> m;

	for (int i=1; i<=m; i++) {
        long long pp, kk, bb, ww;
        cin >> pp >> kk >> bb >> ww;
        seed=bb, base=ww;
        for (int j=ut+1; j<=pp; j++) {
            t[j]=(rnd()%2);
            a[j]=(rnd()%kk)+1;
        }
        ut=pp;
	}

    for (int i=1; i<=n; i++) {
        if (!t[i]) {
            s0+=a[i];
        } else {
            s1+=a[i];
        }
    }
    if (s0>s1 || (s0==s1 && t[1])) {
        for (int i=1; i<=n; i++) {
            t[i]=!t[i];
        }
    }
    if (t[1]) {
        ans[1]++;
    }
    for (int i=1; i<=n; i++) {
        if (!t[i]) {
            sum+=a[i];
            ans[i]=a[i];
        } else {
            long long mini=min(sum, a[i]-ans[i]);
            ans[i]+=mini;
            sum-=mini;
        }
    }
    for (int i=1; i<=n; i++) {
        if (t[i]) {
            long long mini=min(sum, a[i]-ans[i]);
            ans[i]+=mini;
            sum-=mini;
        }
    }
    long long res=1;
    for (long long i=1; i<=n; i++) {
        //cout << i << " " << ans[i] << "\n";
        long long s=((ans[i]^(i*i))+1)%mod;
        res=res*s%mod;
    }
    cout << res << "\n";
    return 0;
}