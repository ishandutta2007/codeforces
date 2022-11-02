#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    int n, x;
    cin >> n;

    int p[n], l[n];
    p[0] = 0;
    int rem[n], dp[n][2]; //subtree size, max_element
    vector<int> dfs;
    vector<int> sons[n];
    fill(rem, rem + n, 0);

    for(int i = 0; i<n; i++){
        cin >> l[i];
    }

    for(int i = 1; i<n; i++){
        cin >> x;
        p[i] = x - 1;
        sons[p[i]].push_back(i);
        rem[p[i]]++;
    }

    for(int i = 0; i<n; i++){
        if(rem[i] == 0) dfs.push_back(i);
    }

    while(!dfs.empty()){
        x = dfs.back();
        dfs.pop_back();
        rem[p[x]]--;
        if(rem[p[x]] == 0) dfs.push_back(p[x]);

        int sum = 0;
        int summi = 0;
        int mindiff = 1e9;
        for(int i = 0; i<sons[x].size(); i++){
            sum += dp[sons[x][i]][0];
            summi += dp[sons[x][i]][1];
            mindiff = min(mindiff, dp[sons[x][i]][0] - dp[sons[x][i]][1]);
        }

        if(sum == 0) dp[x][0] = 1;
        else dp[x][0] = sum;

        if(mindiff == 1e9){
            dp[x][1] = 0;
        }

        else{
            if(l[x] == 0){
                dp[x][1] = summi;
            }

            else{
                dp[x][1] = sum - mindiff;
            }
        }
    }

    cout << dp[0][1]  + 1;


}