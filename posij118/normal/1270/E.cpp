#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    vector<int> ans;
    int x[n], y[n];
    for(int i = 0; i<n; i++){
        cin >> x[i] >> y[i];
        x[i] += 1e8;
        y[i] += 1e8;
    }

    while(1){
        for(int i = 0; i<n; i++){
            if((x[i] + y[i]) & 1) ans.push_back(i + 1);
        }

        if(ans.size() == 0 || ans.size() == n){
            ans.clear();
            for(int j = 0; j<n; j++){
                int op = (x[j] + y[j]) / 2;
                x[j] = (x[j] - y[j] + (int)1e9) / 2 - 5e8;
                y[j]  = op;
            }
        }

        else break;
    }

    cout << ans.size() << endl;
    for(auto x: ans){
        cout << x << " ";
    }

}