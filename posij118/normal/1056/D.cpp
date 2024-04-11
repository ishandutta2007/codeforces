#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, x;
    cin >> n;

    vector<int> sons[n];
    int rem[n];
    fill(rem, rem + n, 0);
    int p[n];

    for(int i = 1; i<n; i++){
        cin >> p[i];
        p[i]--;
        rem[p[i]]++;
        sons[p[i]].push_back(i);
    }

    p[0] = 0;
    vector<int> dfs;
    int num[n];
    fill(num, num + n, 0);

    for(int i = 0; i<n; i++){
        if(rem[i] == 0){
            num[i] = 1;
            dfs.push_back(i);
        }
    }

    while(!dfs.empty()){
        x = dfs[dfs.size() - 1];
        dfs.pop_back();

        rem[p[x]]--;
        if(rem[p[x]] == 0){
            dfs.push_back(p[x]);
            for(int i = 0; i<sons[p[x]].size(); i++){
                num[p[x]] += num[sons[p[x]][i]];
            }
        }

    }

    sort(num, num + n);
    for(int i = 0; i<n; i++){
        cout << num[i] << " ";
    }





}