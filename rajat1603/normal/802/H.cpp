#include "bits/stdc++.h"
using namespace std;
pair < pair < string , string > , string > solve(int n){
    if(n == 1){
        return {{"a" , ""} , "a"};
    }
    if(n == 2){
        return {{"a" , "a"} , "a"};
    }
    int k = n - 1 >> 1;
    auto res = solve(k);
    string c = "";
    c += res.second[res.second.size() - 1] + 1;
    if(k * 2 + 1 == n){
        return {{res.first.first + c , res.first.second + c + c} , res.second + c};
    }
    else{
        return {{res.first.first + c , c + res.first.second + c + c} , res.second + c};
    }
}
int main(){
    int n;
    cin >> n;
    auto it = solve(n);
    cout << it.first.first + it.first.second << " " << it.second << endl;
}