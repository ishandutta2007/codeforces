#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        vector<int> ans;
        int mult = 1;

        while(n){
            if(n % 10) ans.push_back((n % 10) * mult);
            n/=10;
            mult*=10;
        }

        cout << ans.size() << endl;
        for(auto i: ans){
            cout << i << " ";
        }
        cout << endl;
    }

}