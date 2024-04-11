#include "bits/stdc++.h"
using namespace std;
int c , n;
int inp;
map < int , int > mp;
int solve(int val){
    ++mp[val];
    int cur = c;
    int lim = c + 1;
    while(cur){
        auto it = mp.lower_bound(min(cur + 1 , lim));
        if(it == mp.begin()){
            break;
        }
        --it;
        lim = it -> first;
        cur -= it -> first * (min(cur / it -> first , it -> second));
    }
    if(cur){
        return 1;
    }
    --mp[val];
    if(mp[val] == 0){
        mp.erase(val);
    }
    return 0;
}
int main(){
    scanf("%d" , &c);
    scanf("%d" , &n);
    for(int i = 1 ; i <= n ; ++i){
        scanf("%d" , &inp);
        ++mp[inp];
    }
    for(int i = 2 ; i < c ; ++i){
        if(solve(i)){
            printf("%d\n" , i);
            return 0;
        }
    }
    printf("Greed is good\n");
}