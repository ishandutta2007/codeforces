#include "bits/stdc++.h"
using namespace std;
const int N = 2e3 + 3;
int n;
int a , b , c;
int minedge;
vector < pair < int , pair < int , int > > > v;
long long ans[N];
int main(){
    scanf("%d" , &n);
    minedge = 1e9 + 9;
    v.clear();
    for(int i = 1 ; i <= n ; ++i){
        for(int j = i + 1 ; j <= n ; ++j){
            scanf("%d" , &c);
            v.push_back({c , {i , j}});
            minedge = min(minedge , c);
        }
    }
    sort(v.begin() , v.end());
    for(int i = 1 ; i <= n ; ++i){
        ans[i] = INT_MAX;
    }
    for(auto it : v){
        if(it.first == minedge){
            ans[it.second.first] = ans[it.second.second] = 0;
        }
        else{
            it.first -= minedge;
            ans[it.second.second] = min(ans[it.second.second] , min(it.first * 2LL , it.first + ans[it.second.first]));
            ans[it.second.first] = min(ans[it.second.first] , min(it.first * 2LL , it.first + ans[it.second.second]));
        }
    }
    for(int i = 1 ; i <= n ; ++i){
        printf("%lld\n" , ans[i] + 1LL * (n - 1) * minedge);
    }
}