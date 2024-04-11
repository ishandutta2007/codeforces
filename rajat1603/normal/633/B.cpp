#include "bits/stdc++.h"
using namespace std;
int m;
vector < int > ans;
bool check(int n){
    n /= 5;
    int ret = 0;
    while(n){
        ret += n;
        n /= 5;
    }
    return (ret == m);
}
int main(){
    cin >> m;
    for(int i = 1 ; i <= m * 10 ; ++i){
        if(check(i)){
            ans.emplace_back(i);
        }
    }
    cout << int(ans.size()) << endl;
    for(int x : ans){
        cout << x << " ";
    }
}