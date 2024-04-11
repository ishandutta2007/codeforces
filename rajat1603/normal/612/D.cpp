#include "bits/stdc++.h"
using namespace std;
const int N = 1e6 + 6;
int n , k;
pair < int , int > arr[N + N];
int l , r;
int cur = 0;
int lst;
int sum = 0;
int ansl[N];
int ansr[N];
int ans = 0;
int main(){
    scanf("%d %d" , &n , &k);
    for(int i = 1 ; i <= n ; ++i){
        scanf("%d %d" , &l , &r);
        arr[++cur] = make_pair(l , 0);
        arr[++cur] = make_pair(r , 1);
    }
    sort(arr + 1 , arr + 1 + cur);
    for(int i = 1 ; i <= cur ; ++i){
        if(arr[i].second){
            --sum;
            if(sum == k - 1){
                ++ans;     
                ansl[ans] = lst;
                ansr[ans] = arr[i].first;
            }
        }
        else{
            ++sum;
            if(sum == k){
                lst = arr[i].first;
            }
        }
    }
    printf("%d\n" , ans);
    for(int i = 1 ; i <= ans ; ++i){
        printf("%d %d\n" , ansl[i] , ansr[i]);
    }
}