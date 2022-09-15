#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int pref[31][200001];
int f[31][200001];
int cnt[31];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;cin>>n;
    string s;cin>>s;
    for (int i=1;i<=n;i++){
        for (int j=0;j<='z'-'a';j++) pref[j][i]=pref[j][i-1];
        pref[s[i-1]-'a'][i]++;
    }
    for (int t=0;t<='z'-'a';t++){
        for (int i=0;i<=n;i++){
            if (f[t][pref[t][i]]==0) f[t][pref[t][i]]=i;
        }
    }
    int tt;cin>>tt;
    while (tt--){
        string t;cin>>t;
        for (int i=0;i<='z'-'a';i++) cnt[i]=0;
        for (auto i:t) cnt[i-'a']++;
        int res=0;
        for (int i=0;i<='z'-'a';i++) res=max(res,f[i][cnt[i]]);
        cout<<res<<'\n';
    }
    return 0;
}