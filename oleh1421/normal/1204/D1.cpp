#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
#define endl '\n'
//#define int long long
typedef long long ll;
using namespace std;
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string s;cin>>s;
    int cnt=0;
    reverse(s.begin(),s.end());
    for (int i=0;i<s.size();i++){
        if (s[i]=='0') cnt++;
        else if (cnt>0) cnt--;
        else s[i]='0';
    }
    reverse(s.begin(),s.end());
    cout<<s;
    return 0;
}