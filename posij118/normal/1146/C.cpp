#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n, ma, x;
    ma = 0;
    cin >> n;

    vector<int> p, q;
    for(int i = 0; i<7; i++){
        p.clear();
        q.clear();
        for(int j = 1; j<=n; j++){
            if(j & (1 << i)) p.push_back(j);
            else q.push_back(j);
        }

        if(!p.size() || !q.size()) continue;

        cout << p.size() << " " << q.size() << " ";
        for(auto j: p){
            cout << j << " ";
        }

        for(auto j: q){
            cout << j << " ";
        }
        cout << endl;
        fflush(stdout);
        cin >> x;
        ma = max(ma, x);
    }

    cout << -1 << " " << ma << endl;
    fflush(stdout);
}

int main(){
    int t;
    cin >> t;
    for(int i = 0; i<t; i++){
        solve();
    }
}