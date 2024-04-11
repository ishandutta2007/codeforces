#include "bits/stdc++.h"
using namespace std;
const int N = 85;
int n , k;
int arr[N];
bool there[N];
int tot;
set < pair < int , int > > pq;
int nxt[N];
int lst[N];
int ans;
int main(){
    scanf("%d %d" , &n , &k);
    for(int i = 1 ; i <= n ; ++i){
        scanf("%d" , arr + i);
    }
    for(int i = 1 ; i <= n ; ++i){
        lst[i] = n + 1;
    }
    for(int i = n ; i >= 1 ; --i){
        nxt[i] = lst[arr[i]];
        lst[arr[i]] = i;
    }
    for(int i = 1 ; i <= n ; ++i){
        if(!there[arr[i]]){
            if(tot == k){
                there[prev(pq.end()) -> second] = 0;
                pq.erase(prev(pq.end()));
                --tot;
            }
            ++tot;
            there[arr[i]] = 1;
            pq.insert({nxt[i] , arr[i]});
            ++ans;
        }
        else{
            pq.erase(pq.begin());
            pq.insert({nxt[i] , arr[i]});
        }
    }
    printf("%d\n" , ans);
}