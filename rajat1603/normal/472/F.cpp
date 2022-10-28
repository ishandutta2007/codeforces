#include "bits/stdc++.h"
using namespace std;
const int N = 1e4 + 4;
const int LN = 30;
int n;
int a[N];
int b[N];
bool done[N];
vector < pair < int , int > > va;
vector < pair < int , int > > vb;
int solve(int arr[] , vector < pair < int , int > > &res){
    for(int i = 1 ; i <= n ; ++i){
        done[i] = 0;
    }
    for(int i = LN - 1 ; i >= 0 ; --i){
        int idx = -1;
        for(int j = 1 ; j <= n ; ++j){
            if(!done[j] && arr[j] & (1 << i)){
                idx = j;
                break;
            }
        }
        if(idx != -1){
            done[idx] = 1;
            for(int j = 1 ; j <= n ; ++j){
                if(!done[j] && (arr[j] & (1 << i))){
                    arr[j] ^= arr[idx];
                    res.emplace_back(make_pair(j , idx));
                }
            }
        }
    }
    int idx = 1;
    for(int i = LN - 1 ; i >= 0 ; --i){
        for(int j = idx ; j <= n ; ++j){
            if(arr[j] & (1 << i)){
                if(j != idx){
                    arr[j] ^= arr[idx];
                    arr[idx] ^= arr[j];
                    arr[j] ^= arr[idx];
                    res.emplace_back(make_pair(j , idx));
                    res.emplace_back(make_pair(idx , j));
                    res.emplace_back(make_pair(j , idx));
                }
                ++idx;
                break;
            }
        }
    }
    for(int i = idx ; i <= n ; ++i){
        arr[i] ^= arr[i];
        res.emplace_back(make_pair(i , i));
    }
    return idx - 1;
}
set < int > get(int val){
    int lol = 1 << LN;
    int idx = 1;
    set < int > res;
    res.clear();
    for(int i = LN - 1 ; i >= 0 ; --i){
        if(val & (1 << i)){
            while(a[idx] & lol){
                ++idx;
            }
            if(a[idx] & (1 << i)){
                val ^= a[idx];
                res.insert(idx);
            }
            else{
                printf("-1\n");
                exit(0);
            }
        }
        lol |= 1 << i;
    }
    return res;
}
int main(){
    scanf("%d" , &n);
    for(int i = 1 ; i <= n ; ++i){
        scanf("%d" , a + i);
    }
    for(int i = 1 ; i <= n ; ++i){
        scanf("%d" , b + i);
    }
    int b1 = solve(a , va);
    int b2 = solve(b , vb);
    for(int i = 1 ; i <= b2 ; ++i){
        auto it = get(b[i]);
        if(it.find(i) == it.end()){
            it.insert(i);
        }
        else{
            it.erase(i);
        }
        for(auto x : it){
            a[i] ^= a[x];
            va.emplace_back(make_pair(i , x));
        }
    }
    for(int i = b2 + 1 ; i <= n ; ++i){
        a[i] ^= a[i];
        va.emplace_back(make_pair(i , i));
    }
    printf("%d\n" , int(va.size()) + int(vb.size()));
    for(auto it : va){
        printf("%d %d\n" , it.first , it.second);
    }
    reverse(vb.begin() , vb.end());
    for(auto it : vb){
        printf("%d %d\n" , it.first , it.second);
    }
}