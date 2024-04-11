#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
int n , m;
int a[N];
int b[N];
vector < pair < long long , long long > > v;
long long ans;
int main(){
    scanf("%d %d" , &n , &m);
    for(int i = 1 ; i <= n ; ++i){
        scanf("%d" , a + i);
    }
    for(int i = 1 ; i <= m ; ++i){
        scanf("%d" , b + i);
    }
    ans = 0;
    v.clear();
    for(int i = 1 ; i <= n ; ++i){
        v.emplace_back(make_pair(a[i] , int(2e9 + 9)));
    }
    for(int i = 1 ; i <= m ; ++i){
        v.emplace_back(make_pair(b[i] , 0));
    }
    sort(v.begin() , v.end());
    for(int i = 1 ; i < v.size() ; ++i){
        v[i].second = min(v[i].second , v[i - 1].second + v[i].first - v[i - 1].first);
    }
    for(int i = int(v.size()) - 2 ; i >= 0 ; --i){
        v[i].second = min(v[i].second , v[i + 1].second + v[i + 1].first - v[i].first);
    }
    for(auto it : v){
        ans = max(ans , it.second);
    }
    cout << ans;
}