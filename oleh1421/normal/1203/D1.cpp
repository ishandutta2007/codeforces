#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
#define endl '\n'
typedef long long ll;
using namespace std;
ll a[500001];
bool ok(string a,string b){
    int j=0;
    for (int i=0;i<a.size() && j<b.size();i++){
        if (a[i]==b[j]) j++;
    }
    return (j==(int)b.size());
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string s;cin>>s;
    string t;cin>>t;
    int n=(int)s.size();
    int res=0;
    for (int l=0;l<n;l++){
        for (int r=l;r<n;r++){
            string cur="";
            for (int i=0;i<l;i++) cur+=s[i];
            for (int i=r+1;i<n;i++) cur+=s[i];
            if (ok(cur,t)) res=max(res,r-l+1);
        }
    }
    cout<<res;
    return 0;
}