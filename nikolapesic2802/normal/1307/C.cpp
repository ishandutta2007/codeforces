#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf = 2e18;
signed main(){
    string s;
    cin>>s;
    ll freq[s.size()+1][26] = {0};
    freq[s.size()-1][s[s.size()-1]-'a']++;
    for(ll i=(int)s.size()-2;i>=0;i--){
        for(ll j=0;j<26;j++){
            if(j == (s[i]-'a')){
                freq[i][j] = freq[i+1][j]+1;
            }
            else{
                freq[i][j] = freq[i+1][j];
            }
        }
    }
    if(s.size() == 1){
        cout << 1 << '\n';
        return 0;
    }
    if(s.size() == 2){
        if(s[0] == s[1]){
            cout << 2 << '\n';
        }
        else{
            cout << 1 << '\n';
        }
        return 0;
    }
    ll maxa = -inf;
    for(ll j=0;j<26;j++){
        for(ll k=0;k<26;k++){
            ll ans = 0;
            if(j == k){
                ans = freq[0][j]*(freq[0][j]-1)/2;
                maxa = max(maxa,ans);
                continue;
            }
            for(ll i=0;i<s.size();i++){
                if((s[i]-'a') == j){
                   ans+=(freq[i+1][k]);
                } 
            }
            maxa = max(ans,maxa);
        }
    }
    for(ll j=0;j<26;j++){
       maxa = max(maxa,freq[0][j]);
    }
    cout << maxa << '\n';
}