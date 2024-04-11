#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int u, v; cin >> u >> v;
        vector<int> bu, bv;
        for(int i=0;i<30;i++){
            if((1<<i) & u) bu.push_back(i);
            if((1<<i) & v) bv.push_back(i);
        }
        int cnt = 0; bool ans = true;
        if(bv.size() > bu.size()) ans = false;
        else if(bv.size() == bu.size()){
            for(int i=0;i<bv.size();i++){
                if(bu[i] > bv[i]) ans = false;
            }
        }
        else{
            for(int i=0;i<bv.size();i++){
                if(bu[i] > bv[i]) ans = false;
            }
            for(int i=bv.size()-1;i>=0;i--){
                if(bv[i] < bu[bu.size() - bv.size() + i]) ans = false;
                if(bv[i] != bu[bu.size() - bv.size() + i]) break;
                if(i == 0) ans = false;
            }
        }

        if(ans) cout << "YES\n";
        else cout << "NO\n";
    }
}