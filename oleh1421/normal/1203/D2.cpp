#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
#define endl '\n'
typedef long long ll;
using namespace std;
int l[200001];
int r[200001];
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string s;cin>>s;
    string t;cin>>t;
    int j=0;
    for (int i=0;i<s.size() && j<t.size();i++){
        if (s[i]==t[j]){
            l[j]=i;
            j++;
        }
    }
    reverse(s.begin(),s.end());
    reverse(t.begin(),t.end());
    j=0;
    for (int i=0;i<s.size() && j<t.size();i++){
        if (s[i]==t[j]){
            r[(int)t.size()-j-1]=(int)s.size()-i-1;
            j++;
        }
    }
    int res=0;
    for (int i=0;i+1<t.size();i++){
        res=max(res,r[i+1]-l[i]-1);
    }
    res=max(res,r[0]);
    res=max(res,(int)s.size()-l[(int)t.size()-1]-1);
    cout<<res;
    return 0;
}