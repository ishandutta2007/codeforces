#include <bits/stdc++.h>
using namespace std;
string s;
char mp[101][101];
int n,i,j,k;
int main() {
    cin>>n;
    for (i=1;i<=n;i++) {
        for (j=1;j<=n;j++) cin>>mp[i][j];
    }
    for (i=1;i<=n;i++) for (j=1;j<=n;j++) {
        if (i+6<=n) {
            s="";
            for (k=0;k<7;k++) s.push_back(mp[i+k][j]);
            if (s=="theseus") return cout<<"YES",0;
        }
        if (j+6<=n) {
            s="";
            for (k=0;k<7;k++) s.push_back(mp[i][j+k]);
            if (s=="theseus") return cout<<"YES",0;
        }
        if (i+6<=n && j+6<=n) {
            s="";
            for (k=0;k<7;k++) s.push_back(mp[i+k][j+k]);
            if (s=="theseus") return cout<<"YES",0;
        }
    }
    cout<<"NO";
}