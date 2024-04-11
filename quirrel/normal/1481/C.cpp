#include<bits/stdc++.h>
using namespace std;
int a[100009],b[100009],c[100009];
vector<int> v[100009];
main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        for(int i = 1; i <= n; i++){
            cin >> a[i];
        }
        for(int i = 1; i <= n; i++){
            cin >> b[i];
        }
        for(int i = 1; i <= m; i++){
            cin >> c[i];
        }
        int ok = 0;
        for(int i = 1; i <= n; i++){
            if(b[i] == c[m]) ok = i; 
        }
        if(!ok) {
            cout <<"NO"<<endl;
            continue;
        }
        int bad = 0;
        for(int i = 1; i <= n; i++){
            if(b[i] != a[i]) v[b[i]].push_back(i), bad++;
        }
        vector<int> ans;
        for(int i = m; i >= 1; i--){
            if(!v[c[i]].size()) 
            {        if(i == m) ans.push_back(ok); 
                     else ans.push_back(ans[0]);
                     continue;}
            ans.push_back(v[c[i]].back());
            v[c[i]].pop_back();
            bad--;
        }
        if(bad) cout<<"NO"<<endl;
        else{
            
            cout<<"YES"<<endl;
            reverse(ans.begin(),ans.end());
            for(int x : ans)
                cout<<x<<" ";
                cout<<endl;
        }
        for(int i = 1; i <= n; i++)
            v[i].clear();
    }
}