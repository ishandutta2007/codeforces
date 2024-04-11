#include "bits/stdc++.h"
using namespace std;
const int N = 2e5 + 5;
int n , k , s , t;
int c[N];
int vv[N];
int ans;
int pos[N];
vector < pair < int , long long > > v;
bool solve(int val){
    if(v.back().first > val){
        return 0;
    }
    auto it = lower_bound(v.begin() , v.end() , make_pair(val >> 1 , 1LL << 60));
    --it;
    long long res = 0;
    res += it -> second;
    int idx = it - v.begin();
    int cnt = v.size() - idx - 1;
    res -= 1LL * cnt * val;
    res += 3LL * (v.back().second - it -> second);
    return res <= t;
}
int main(){
    scanf("%d %d %d %d" , &n , &k , &s , &t);
    for(int i = 1 ; i <= n ; ++i){
        scanf("%d %d" , &c[i] , &vv[i]);
    }
    ans = 2e9 + 9;
    for(int i = 1 ; i <= k ; ++i){
        scanf("%d" , pos + i);
    }
    sort(pos + 1 , pos + 1 + k);
    pos[0] = 0;
    pos[k + 1] = s;
    for(int i = 1 ; i <= k + 1 ; ++i){
        v.push_back(make_pair(pos[i] - pos[i - 1] , 0));
    }
    v.push_back(make_pair(0 , 0));
    sort(v.begin() , v.end());
    for(int i = 1 ; i < v.size() ; ++i){
        v[i].second = v[i - 1].second + v[i].first;
    }
    for(int i = 1 ; i <= n ; ++i){
        if(solve(vv[i])){
            ans = min(ans , c[i]);
        }
    }
    if(ans > 2e9){
        ans = -1;
    }
    printf("%d\n" , ans);
}