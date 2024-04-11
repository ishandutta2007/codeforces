#include <bits/stdc++.h>
#define int long long
using namespace std;
int A[26];
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        int i;
        for(i=0;i<26;i++) A[i] = 0;
        for(i=0;i<s.length();i++) A[s[i]-'a']++;
        for(i=0;i<26;i++) {
            if(A[i]==2) cout << (char)(i+'a');
        }
        for(i=0;i<26;i++) {
            if(A[i]==2) cout << (char)(i+'a');
        }
        for(i=0;i<26;i++) {
            if(A[i]==1) cout << (char)(i+'a');
        }
        cout << '\n';
    }
}