#include <bits/stdc++.h>
using namespace std;

void solve(){
    string s1, s2;
    cin >> s1 >> s2;
    int n = s1.size();
    int m = s2.size();
    vector<int> pos[26];
    for(int i = 0; i<n; ++i)
        pos[s1[i]-'A'].push_back(i);
    vector<int> bruh;
    for(int i = m-1; i>=0; --i){
        if(pos[s2[i]-'A'].empty()){
            cout << "NO" << '\n';
            return;
        }
        bruh.push_back(pos[s2[i]-'A'].back());
        pos[s2[i]-'A'].pop_back();
    }
    reverse(bruh.begin(), bruh.end());
    for(int i = 0; i<m-1; ++i){
        if(bruh[i]>bruh[i+1]){
            cout << "NO" << '\n';
            return;
        }
    }
    cout << "YES" << '\n';
}

int main(){
    // freopen("a.in", "r", stdin);
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}