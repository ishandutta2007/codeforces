#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, skap;
    vector<int> ans;
    cin >> n;

    int a[n + 1];
    int diff[n + 1];
    a[0] = 0;
    for(int i = 0; i<n; i++){
        cin >> a[i + 1];
    }

    for(int k = 1; k<=n; k++){
        fill(diff, diff + n + 1, 1e9);
        skap = 0;

        for(int i = 1; i<=n; i++){
            if(diff[(i - 1) % k] != 1e9){
                if(diff[(i - 1) % k] != (a[i] - a[i - 1])) skap = 1;
            }

            else diff[(i - 1) % k] = a[i] - a[i - 1];
        }

        if(skap == 0) ans.push_back(k);
    }

    cout << ans.size() << endl;
    for(int i = 0; i<ans.size(); i++){
        cout << ans[i] << " ";
    }



}