#include <bits/stdc++.h>

using namespace std;
const int c=1500005;
string a, b, x, s;
int pr[c], z[c], n, m, k, mp[c], ms[c];
long long db[c], cnt[c], f, sum, ans;
#define lsb(i) (i & (-i))
void add(int a, int b) {
    if (b==0) return;
    if (b>0) f++;
    else f--;
    sum+=b;
    while(a<c) {
        if (b>0) db[a]++;
        else db[a]--;
        cnt[a]+=b;
        a+=lsb(a);
    }
}
long long ask(int a) {
    a=max(a, 0);
    long long x=0, y=0, aa=a;
    while(aa) {
        x+=db[aa], y+=cnt[aa];
        aa-=lsb(aa);
    }
    return sum-y-(f-x)*a;
}
void zz(string s) {
    int n = (int) s.length();
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r)
            z[i] = min (r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> a >> b >> x, k=n+m+1;
    s+=x, s+='_', s+=a;
    zz(s);
    for (int i=0; i<k; i++) pr[i]=z[i], z[i]=0;
    s.clear();
    reverse(b.begin(), b.end()), reverse(x.begin(), x.end());
    s+=x, s+='_', s+=b;
    zz(s);
    for (int i=m+1; i<k; i++) {
        int x=pr[i], y=z[i];
        mp[i-m]=x;
        ms[k-i]=y;
    }
    for (int i=1; i<=n; i++) {
        mp[i]=min(m-1, mp[i]);
        ms[i]=min(m-1, ms[i]);
    }
    for (int i=1; i<=min(m-1, n); i++) {
        add(ms[i], ms[i]);
    }
    for (int i=1; i<=n; i++) {
        ans+=ask(m-1-mp[i]);
        add(ms[i], -ms[i]);
        if (i+m-1<=n) add(ms[i+m-1], ms[i+m-1]);
    }
    cout << ans << "\n";
    return 0;
}