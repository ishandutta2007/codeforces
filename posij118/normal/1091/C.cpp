#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n;
    cin >> n;
    vector<long long> ans;

    for(int i = 1; i*i <=n; i++){
        if(n % i == 0){
            ans.push_back(n / i + (i*((n / i - 1)*(n / i))) / 2);
            if(i*i < n){
               ans.push_back(i + ((n/i)*((i - 1)*(i))) / 2);
            }
        }
    }

    sort(ans.begin(), ans.end());
    for(int i = 0; i<ans.size(); i++){
        cout << ans[i] << " ";
    }

}