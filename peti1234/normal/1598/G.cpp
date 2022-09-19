#include <bits/stdc++.h>

using namespace std;
const int c=700005, k=20;
long long mod[k], po[k][c], ert[k][c], bert[k], n, m, si;
string a, b, u;
vector<int> zf;

vector<int> z_function(string s) {
    int n = (int) s.length();
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r)
            z[i] = min (r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    return z;
}
void ch(int a1, int a2, int b1, int b2) {
    if (a1<0 || b2>n || a1>=a2 || b1>=b2) return;
    for (int j=0; j<k; j++) {
        long long s1=(ert[j][a2]-ert[j][a1]+mod[j])%mod[j]*po[j][a2+1]%mod[j], s2=(ert[j][b2]-ert[j][b1]+mod[j])%mod[j]*po[j][b2+1]%mod[j];
        if ((s1+s2)%mod[j]!=bert[j]) {
            return;
        }
    }

    cout << a1+1 << " " << a2 << "\n" << b1+1 << " " << b2 << "\n";
    exit(0);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> a >> b;
    u=b+"#"+a;
    n=a.size(), m=b.size(), si=u.size();
    zf=z_function(u);
    srand(time(0));
    for (int j=0; j<k; j++) {
        mod[j]=1e9+1+rand()*rand();
        po[j][0]=1;
        for (int i=1; i<=si; i++) po[j][i]=po[j][i-1]*10%mod[j];
        for (int i=1; i<=n; i++) ert[j][i]=(ert[j][i-1]+po[j][n-i+1]*(a[i-1]-'0'))%mod[j];
        for (int i=0; i<m; i++) bert[j]=(bert[j]+po[j][si-i]*(b[i]-'0'))%mod[j];
    }
    for (int i=0; i<n; i++) {
        ch(i, i+m-1, i+m-1, i+2*m-2);
        int ert=zf[m+1+i];
        ch(i-m+ert, i, i, i+m), ch(i, i+m, i+m, i+2*m-ert);
        ch(i-m+ert+1, i, i, i+m), ch(i, i+m, i+m, i+2*m-ert-1);
    }
    return 0;
}