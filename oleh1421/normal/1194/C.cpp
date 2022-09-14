#include <bits/stdc++.h>
//#define int long long
typedef long long ll;
using namespace std;
int cnt[31];
bool ok(string s,string t,string p){
     for (int i=0;i<='z'-'a';i++) cnt[i]=0;
     for (auto i:p) cnt[i-'a']++;
     int j=0;
     for (int i=0;i<t.size();i++){
         if (j<s.size() && s[j]==t[i]){
             j++;
         } else {
             cnt[t[i]-'a']--;
             if (cnt[t[i]-'a']<0) return 0;
         }
     }
     return (j==(int)s.size());
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tt;cin>>tt;
    while (tt--){
        string s,t,p;cin>>s>>t>>p;
        if (ok(s,t,p)) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}
//2 6 -2 -6  2