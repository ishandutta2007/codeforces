#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
using namespace std;

ll N,M,R,C;
string s,t,p;
int main (){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    ll T; cin>>T;
    while (T--){
        cin >> s >> t >> p;
        ll locs=0, loct=0, alp[30];
        memset(alp,0,sizeof(alp));
        while (s[locs] and t[loct] and locs<s.size() and loct<t.size()){
            if (s[locs]==t[loct]){
                locs++;
                t[loct]='0';
            }
            loct++;
            // cout << loct << endl;
        }
        // cout << locs << "\n";
        if (locs<s.size()){
            cout << "NO\n";
            continue;
        }
        for (ll i=0; i<t.size(); i++){
            if(t[i]=='0') continue;
            alp[t[i]-'a']++;
        }
        for (ll i=0; i<p.size(); i++){
            alp[p[i]-'a']--;
        }
        int cek=0;
        for (ll i=0; i<30; i++){
           if (alp[i]<=0) continue;
           cek=1;
           break;
        }
        if (cek==1){
            cout << "NO\n";
        } else{
            cout << "YES\n";
        }
    }
    

}