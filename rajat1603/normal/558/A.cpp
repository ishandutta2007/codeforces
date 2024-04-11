#include "bits/stdc++.h"
using namespace std;
const int N = 1 << 7;
vector < pair < int , int > > v1;
vector < pair < int , int > > v2;
int n;
int x;
int y;
int ans = 0;
int main(){
    cin >> n;
    for(int i = 1 ; i <= n ; ++i){
        cin >> x >> y;
        if(x < 0){
            v1.emplace_back(make_pair(-x , y));
        }
        else{
            v2.emplace_back(make_pair(x , y));
        }
    }
    sort(v1.begin() , v1.end());
    sort(v2.begin() , v2.end());
    if(v1.size() == v2.size()){
        for(auto x : v1){
            ans += x.second;
        }
        for(auto x : v2){
            ans += x.second;
        }
    }
    else if(v1.size() < v2.size()){
        auto ite = v2.begin();
        for(auto it : v1){
            ans += it.second;
            ans += ite -> second;
            ++ite;
        }
        ans += ite -> second;
    }
    else{
        auto ite = v1.begin();
        for(auto it : v2){
            ans += it.second;
            ans += ite -> second;
            ++ite;
        }
        ans += ite -> second;
    }
    cout << ans << endl;
}