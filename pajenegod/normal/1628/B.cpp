// not my code: https://codeforces.com/contest/1628/submission/147507140
 
#include <bits/stdc++.h>
using namespace std;
 
#define fr(i,n) for(int i = 0; i<n; i++)
#define sz(v) (int)(v.size())
#define prin(a) cout << #a << " = " << a << endl
#define prinv(v) cout << #v << " = "; for(auto it : v) cout << it << ", "; cout << endl
#define all(v) (v).begin(),(v).end()
 
typedef long long ll;
 
#define rmin(a,b) a = min<ll>(a,b)
#define rmax(a,b) a = max<ll>(a,b)
 
#define fi first
#define se second
 
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    fr(tt,t){
        int n; cin >> n;
        vector<string> st, v;
        int ok = 0;
        fr(i,n){
            
            string s; cin >> s;
            st.emplace_back(s);
            
        }
        v = st;
        sort(all(st));
        
        {
            multiset<string> sa, sd(all(v));
            
            for(auto &s : v){
                sa.insert(s);
                sd.erase(sd.find(s));
                if(sz(s)==3){
                    string s_dep = string()+s[1]+s[0];
                    if(distance(sd.lower_bound(s_dep), sd.upper_bound(s_dep))) ok = 1;
                    
                    string s_ant = string()+s[2]+s[1];
                    if(distance(sa.lower_bound(s_ant), sa.upper_bound(s_ant))) ok = 1;
                }
            }
            
        }
        
        for(auto s : st){
            if(ok) break;
            reverse(all(s));
            if(binary_search(all(st),s)) ok = 1;
        }
        if(ok) cout << "YES\n";
        else cout << "NO\n";
    }
    
}