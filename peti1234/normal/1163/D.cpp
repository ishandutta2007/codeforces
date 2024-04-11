#include <bits/stdc++.h>

using namespace std;
const int c=1002, kk=52;
int n, dp[c][kk][kk], jokov[kk][26], rosszkov[kk][26], sjo, srossz, maxi=-c;
string s, jo, rossz;
vector<int> pref;

vector<int> kmp(string s) {
    int n = (int)s.length();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}

int main()
{
    cin >> s >> jo >> rossz;
    n=s.size(), sjo=jo.size(), srossz=rossz.size();
    pref=kmp(jo);
    for (int i=0; i<=sjo; i++) {
        int ert=0;
        for (char j='a'; j<='z'; j++, ert++) {
            int pos=i;
            while (pos) {
                if (pos<sjo && jo[pos]==j) {
                    break;
                }
                pos=pref[pos-1];
            }
            jokov[i][ert]=pos+(jo[pos]==j);
        }
    }
    pref=kmp(rossz);
    for (int i=0; i<=srossz; i++) {
        int ert=0;
        for (char j='a'; j<='z'; j++, ert++) {
            int pos=i;
            while (pos) {
                if (pos<srossz && rossz[pos]==j) {
                    break;
                }
                pos=pref[pos-1];
            }
            rosszkov[i][ert]=pos+(rossz[pos]==j);
        }
    }
    for (int i=0; i<c; i++) {
        for (int j=0; j<kk; j++) {
            for (int k=0; k<kk; k++) {
                dp[i][j][k]=-c;
            }
        }
    }
    dp[0][0][0]=0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<=sjo; j++) {
            for (int k=0; k<=srossz; k++) {
                if (j==sjo) {
                    dp[i][j][k]++;
                }
                if (k==srossz) {
                    dp[i][j][k]--;
                }
                int ert=0;
                for (char c='a'; c<='z'; c++, ert++) {
                    if (s[i]==c || s[i]=='*') {
                        int s1=jokov[j][ert], s2=rosszkov[k][ert];
                        dp[i+1][s1][s2]=max(dp[i+1][s1][s2], dp[i][j][k]);
                    }
                }
            }
        }
    }
    for (int j=0; j<=sjo; j++) {
        for (int k=0; k<=srossz; k++) {
            if (j==sjo) {
                dp[n][j][k]++;
            }
            if (k==srossz) {
                dp[n][j][k]--;
            }
            maxi=max(maxi, dp[n][j][k]);
        }
    }
    cout << maxi << "\n";
    return 0;
}