#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
const int LN = 17;
int n;
int arr[N];
bool check(int val , bool print){
    map < int , int > mp;
    mp.clear();
    for(int i = 1 ; i <= n ; ++i){
        int tmp = arr[i];
        while(tmp > val){
            tmp >>= 1;
        }
        ++mp[tmp];
    }
    vector < int > ans;
    ans.clear();
    while(!mp.empty()){
        auto it = prev(mp.end());
        if(it -> first < 1){
            break;
        }
        ans.emplace_back(it -> first);
        if(it -> second > 1){
            mp[it -> first >> 1] += it -> second - 1;
        }
        mp.erase(it);
    }
    if(ans.size() == n){
        if(print){
            for(int i = 1 ; i <= n ; ++i){
                printf("%d%c" , ans[i - 1] , " \n"[i == n]);
            }
        }
        return 1;
    }
    else{
        return 0;
    }
}
int main(){
    scanf("%d" , &n);
    for(int i = 1 ; i <= n ; ++i){
        scanf("%d" , &arr[i]);
    }
    int l = n;
    int r = 1e9 + 1;
    while(l < r){
        int mid = l + r >> 1;
        if(check(mid , 0)){
            r = mid;
        }
        else{
            l = mid + 1;
        }
    }
    check(l , 1);
}