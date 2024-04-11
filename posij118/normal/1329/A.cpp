#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int n, m;
    cin >> n >> m;
 
    int cur = n + 1;
    long long sum = 0;
    int l[m];
 
    for(int i = 0; i<m; i++){
        cin >> l[i];
        sum += l[i];
    }
 
    if(sum < n){
        cout << -1;
        return 0;
    }
 
    vector<int> ans;
    for(int i = m - 1; i>=0; i--){
        cur = max(i + 1, cur - l[i]);
        if(cur + l[i] > n + 1){
            cout << -1;
            return 0;
        }
        ans.push_back(cur);
    }
 
    reverse(ans.begin(), ans.end());
    for(auto x: ans){
        cout << x << " ";
    }
 
}