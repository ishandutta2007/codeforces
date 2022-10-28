#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
int n , k;
string str;
vector < int > v;
int ans;
set < int > s;
inline int dist(int mid , int l , int r){
    return max(r - mid , mid - l);
}
inline int get(int l , int r){
    int mid = v[l] + v[r] >> 1;
    auto it1 = s.lower_bound(mid);
    auto it2 = prev(it1);
    return min(dist(*it1 , v[l] , v[r]) , dist(*it2 , v[l] , v[r]));
}
int main(){
    cin >> n >> k;
    cin >> str;
    s.insert(-1e9);
    s.insert(1e9);
    for(int i = 0 ; i < n ; ++i){
        if(str[i] == '0'){
            v.emplace_back(i + 1);
        }
    }
    int l = 0;
    int r = k;
    for(int i = l ; i <= r ; ++i){
        s.insert(v[i]);
    }
    ans = get(l , r);
    ++r;
    ++l;
    s.erase(v[0]);
    while(r < v.size()){
        s.insert(v[r]);
        ans = min(ans , get(l , r));
        ++r;
        s.erase(v[l]);
        ++l;
    } 
    cout << ans;
}