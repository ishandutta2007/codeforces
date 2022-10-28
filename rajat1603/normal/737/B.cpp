#include "bits/stdc++.h"
using namespace std;
const int N = 2e5 + 5;
int n , a , b , k;
char str[N];
vector < pair < int , int > > v;
vector < int > ans;
int main(){
    scanf("%d %d %d %d" , &n , &a , &b , &k);
    scanf("%s" , str + 1);
    int last = 0;
    v.clear();
    for(int i = 1 ; i <= n ; ++i){
        if(str[i] == '1'){
            if(i - last - 1 > 0){
                v.push_back(make_pair(last + 1 , i - 1));
            }
            last = i;
        }
    }
    if(n - last > 0){
        v.push_back(make_pair(last + 1 , n));
    }
    ans.clear();
    int tot = 0;
    for(auto it : v){
        int sz = it.second - it.first + 1;
        tot += sz / b;
    }
    for(auto it : v){
        int sz = it.second - it.first + 1;
        if(sz < b){
            continue;
        }
        if((sz % b) == (b - 1)){
            int start = it.first + b - 1;
            int cur = sz / b;
            int loltot = tot;
            while(start <= it.second && loltot >= a){
                ans.push_back(start);
                cur = (it.second - start) / b;
                start += b;
                loltot = (tot - (sz / b)) + cur;
            }
            tot = loltot;
        }
    }
    for(auto it : v){
        int sz = it.second - it.first + 1;
        if(sz < b){
            continue;
        }
        if((sz % b) == (b - 1)){
            continue;
        }
        int start = it.first + b - 1;
        int cur = sz / b;
        int loltot = tot;
        while(start <= it.second && loltot >= a){
            ans.push_back(start);
            cur = (it.second - start) / b;
            start += b;
            loltot = (tot - (sz / b)) + cur;
        }
        tot = loltot;
    }
    printf("%d\n" , int(ans.size()));
    for(int x : ans){
        printf("%d " , x);
    }
    printf("\n");
}