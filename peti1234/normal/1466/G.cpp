#include <bits/stdc++.h>

using namespace std;
const int c=1000002, k=27, mod=1000000007;
int n, q, cnt, pi[5*c];
long long kom[c][k], po[c], ert[k];
string alap, s;
vector<string> sz;
int valt(char c) {
    return c-'a'+1;
}
char vvalt(int a) {
    return 'a'+a-1;
}
int kmp(string s, int ert) {
    int n=s.size(), ans=0;
    for (int i=1; i<n; i++) {
        int j=pi[i-1];
        while(j && s[i]!=s[j]) {
            j=pi[j-1];
        }
        if (s[i]==s[j]) {
            j++;
        }
        pi[i]=j;
        if (j==ert) {
            ans++;
        }
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0);
    cin >> n >> q >> alap >> s;
    while(alap.size()<2*c) {
        sz.push_back(alap);
        alap=alap+s[cnt]+alap;
        cnt++;
    }
    po[0]=1;
    for (int i=1; i<c; i++) {
        po[i]=po[i-1]*2%mod;
    }
    for (int i=0; i<n; i++) {
        int pos=valt(s[i]);
        for (int j=1; j<k; j++) {
            kom[i+1][j]=(kom[i][j]*2+(pos==j))%mod;
        }
    }
    for (int i=1; i<=q; i++) {
        int ki, pos=0, si;
        string x;
        cin >> ki >> x, si=x.size();
        while(si>sz[pos].size()) {
            pos++;
        }
        ert[0]=kmp(x+"."+sz[pos], si);
        for (int i=1; i<k; i++) {
            ert[i]=kmp(x+"."+sz[pos]+vvalt(i)+sz[pos], si)-2*ert[0];
        }
        if (ki<pos) {
            cout << 0 << "\n";
        } else {
            long long ans=ert[0]*po[ki-pos]%mod;
            for (int i=1; i<k; i++) {
                long long add=kom[ki][i]-kom[pos][i]*po[ki-pos]%mod;
                if (add<0) {
                    add+=mod;
                }
                ans+=add*ert[i];
            }
            cout << ans%mod << "\n";
        }
    }
    return 0;
}