#include <bits/stdc++.h>

using namespace std;
long long mod1=1000000007, mod2=998244353;
long long base1=29, base2=31;
long long w, k, v;
string s;
void sol()
{
    long long em=0, hm=0;
    long long ha1 = 0, ha2 = 0, hr1 = 0, hr2 = 0;
    long long m1 = 1, m2 = 1;
    long long a=0, b=0;
    for (long long i=k; i<=v; i++) {
        long long x=s[i]-'a'+1;
        ha1 = (ha1 + m1*x) % mod1;
        ha2 = (ha2 + m2*x) % mod2;

        hr1 = (x + base1*hr1) % mod1;
        hr2 = (x + base2*hr2) % mod2;

        m1 *= base1, m1 %= mod1;
        m2 *= base2, m2 %= mod2;
        if ( ha1 == hr1 && ha2 == hr2 ) em=i-k;
    }
    ha1=0, ha2=0, hr1=0, hr2=0, m1=1, m2=1;
    for (long long i=v; i>=k; i--) {
        long long x=s[i]-'a'+1;
        ha1 = (ha1 + m1*x) % mod1;
        ha2 = (ha2 + m2*x) % mod2;

        hr1 = (x + base1*hr1) % mod1;
        hr2 = (x + base2*hr2) % mod2;

        m1 *= base1, m1 %= mod1;
        m2 *= base2, m2 %= mod2;
        //cout << ha1 << " " << hr1 << " " << ha2 << " " << hr2 << " " << m1 << " " << m2 << " " << x << " " << i << endl;
        if ( ha1 == hr1 && ha2 == hr2 ) hm=v-i;
    }
    if (em>hm) {
        for (long long i=k; i<=k+em; i++) cout << s[i];
    } else {
        for (long long i=v-hm; i<=v; i++) {
            cout << s[i];
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> s;
        k=-1, v=s.size();
        while (v-k>3 && s[k+1]==s[v-1]) k++, v--;
        k++, v--;
        for (long long i=0; i<k; i++) cout << s[i];
        sol();
        for (long long i=v+1; i<s.size(); i++) cout << s[i];
        cout << "\n";
    }
    return 0;
}