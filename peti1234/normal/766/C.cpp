#include <bits/stdc++.h>

using namespace std;
int n;
string s;
long long dp[1005];
int t[1001];
int k[30];
int lh[1001];
void meddig(int x)
{
    int hossz=1;
    int minim=t[x];
    int i=x+1;
        while (i<=n && t[i]>hossz && minim>hossz) {
            minim=min(minim, t[i]);
            hossz++;
            i++;
        }

    lh[x]=hossz;
    return;
}
int main()
{
    cin >> n >> s;
    for (int i=1; i<=26; i++) {
        cin >> k[i];
    }
    for (int i=0; i<s.size(); i++) {
        t[i+1]=k[s[i]-'a'+1];
    }
    int hossz=0, mini=INT_MAX, vagas=0;
    for (int i=1; i<=n; i++) {
        if (mini>hossz && t[i]>hossz) {
            hossz++;
            mini=min(mini, t[i]);
        }
        else {
            vagas++;
            hossz=1;
            mini=t[i];
        }
    }

    if (hossz!=0) {
        vagas++;
    }
    for (int i=1; i<=n; i++) {
        meddig(i);
    }
    int maxi=0;
    for (int i=1; i<=n; i++) {
        if (lh[i]>maxi) {
            maxi=lh[i];
        }
    }
    dp[n+1]=1;
    for (int i=n; i>=1; i--) {
        for (int j=1; j<=lh[i]; j++) {
            dp[i]+=dp[i+j];
            dp[i]=dp[i]%1000000007;
        }
    }
    cout << dp[1] << endl;
    cout << maxi << endl;
    cout << vagas << endl;
    return 0;
}