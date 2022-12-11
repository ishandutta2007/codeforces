#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define INF 1e9
#define mp make_pair
#define fi first
#define se second

int k[26];

int c(string s){
    int ans = 0;
    for(int j = 0;j<s.size();j++){
        ans += k[s[j]-97]*(j+1);
    }
    return ans;
}

int main(){

    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    string s;
    cin >> s;
    int ins;
    cin >> ins;
    string v;
    int mx = 0;
    int i = 0;
    for(int j = 0;j<26;j++){
        cin >> k[j];
        if(k[j]>mx){
            mx = k[j];
            i = j;
        }
    }
    for(int x = 0;x<ins;x++){
        v += char(i+97);
    }
    cout << max(c(s+v),c(v+s));
    return 0;
}