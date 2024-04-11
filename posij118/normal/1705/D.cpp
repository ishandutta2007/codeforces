#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    
    while(t--){
        int n;
        string s, t;
        cin >> n >> s >> t;
        
        if(s[0] != t[0] || s[n - 1] != t[n - 1]){
            cout << -1 << endl;
            continue;
        }
        
        vector<pair<int, int> > sc, tc;
        int l = -1;
        
        for(int i = 0; i<n; i++){
            if(s[i] == '1' && l == -1) l = i;
            if(s[i] == '1' && i == n - 1) sc.push_back({l, n - 1});
            else if(s[i] == '1' && s[i + 1] == '0'){
                
                sc.push_back({l, i});
                l = -1;
            }
        }
        
        l = -1;
        
        for(int i = 0; i<n; i++){
            if(t[i] == '1' && l == -1) l = i;
            if(t[i] == '1' && i == n - 1) tc.push_back({l, n - 1});
            else if(t[i] == '1' && t[i + 1] == '0'){
                
                tc.push_back({l, i});
                l = -1;
            }
        }
        
        if(sc.size() != tc.size()){
            cout << -1 << endl;
            continue;
        }
        
        long long ans = 0;
        for(int i = 0; i<sc.size(); i++){
            ans += abs(sc[i].first - tc[i].first) + abs(sc[i].second - tc[i].second);
        }
        
        cout << ans << endl;
        
    }
}