#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){

    int n;
    long long W;
    cin >> n >> W;

    long long w[n];
    vector<pair<int, int> > ww;
    for(int i = 0; i<n; i++){
        cin >> w[i];
        if(w[i] <= W) ww.push_back({w[i], i});
    }

    sort(ww.begin(), ww.end());
    reverse(ww.begin(), ww.end());

    if(ww.empty()){
        cout << -1 << endl;
        continue;
    }

    vector<int> ans;

    long long sum = 0;
    bool flag = 0;
    for(auto x: ww){
        sum += x.first;
        ans.push_back(x.second + 1);
        if(sum >= (W + 1) / 2){
            cout << ans.size() << endl;
            for(auto y: ans){
                cout << y << " ";
            }
            cout << endl;
            flag = 1;
            break;
        }
    }

    if(!flag){
        cout << -1 << endl;
        continue;
    }

    }
}