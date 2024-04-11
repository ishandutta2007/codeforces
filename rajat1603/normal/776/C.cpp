#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
const long long MX = 1e14 + 14;
int n , k;
int arr[N];
vector < long long > v;
map < long long , int > mp;
void pre(){
    v.clear();
    if(k == 1){
        v.emplace_back(1);
    }
    else if(k == -1){
        v.emplace_back(1);
        v.emplace_back(-1);
    }
    else{
        long long cur = 1;
        while(abs(cur) <= MX){
            v.emplace_back(cur);
            cur *= k;
        }
    }
}
int main(){
    scanf("%d %d" , &n , &k);
    for(int i = 1 ; i <= n ; ++i){
        scanf("%d" , arr + i);
    }
    pre();
    long long sum = 0;
    mp.clear();
    ++mp[sum];
    long long ans = 0;
    for(int i = 1 ; i <= n ; ++i){
        sum += arr[i];
        for(auto it : v){
            if(mp.find(sum - it) != mp.end()){
                ans += mp[sum - it];
            }
        }
        ++mp[sum];
    }
    printf("%lld\n" , ans);
}