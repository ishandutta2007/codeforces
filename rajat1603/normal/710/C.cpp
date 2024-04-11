#include "bits/stdc++.h"
using namespace std;
vector < vector < int > > solve(int n){
    if(n == 1){
        return vector < vector < int > > (1 , vector < int > (1 , 1));
    }
    auto it = solve(n - 2);
    vector < vector < int > > res;
    res.clear();
    res.resize(n);
    int cnt1 = 0;
    int cnt2 = 0;
    for(int i = 0 ; i < n - 2 ; ++i){
        if(it[i][0] & 1){
            cnt1 += 2;
            res[i + 1].clear();
            res[i + 1].emplace_back(1);
            for(int x : it[i]){
                res[i + 1].emplace_back(x);
            }
            res[i + 1].emplace_back(1);
        }
        else{
            cnt2 += 2;
            res[i + 1].clear();
            res[i + 1].emplace_back(0);
            for(int x : it[i]){
                res[i + 1].emplace_back(x);
            }
            res[i + 1].emplace_back(0);   
        }
    }
    res[0].clear();
    if(cnt1 < cnt2){
        res[0].emplace_back(1);
    }
    else{
        res[0].emplace_back(0);
    }
    for(int i = 0 ; i < n - 2 ; ++i){
        if(it[0][i] == 1){
            res[0].emplace_back(1);
        }
        else{
            res[0].emplace_back(0);
        }
    }
    res[0].emplace_back(res[0][0]);
    res[n - 1] = res[0];
    return res;
}
int main(){
    int n;
    cin >> n;
    auto it = solve(n);
    int cur1 = 1;
    int cur2 = 2;
    for(int i = 0 ; i < n ; ++i){
        for(int j = 0 ; j < n ; ++j){
            if(it[i][j] & 1){
                printf("%d%c" , cur1 , " \n"[j == n - 1]);
                cur1 += 2;
            }
            else{
                printf("%d%c" , cur2 , " \n"[j == n - 1]);
                cur2 += 2;
            }
        }
    }
}