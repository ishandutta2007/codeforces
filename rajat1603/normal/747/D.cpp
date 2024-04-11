#include "bits/stdc++.h"
using namespace std;
const int N = 2e5 + 5;
int n , k;
int arr[N];
vector < pair < int , int > > v;
int ans;
int start;
int main(){
    scanf("%d %d" , &n , &k);
    for(int i = 1 ; i <= n ; ++i){
        scanf("%d" , arr + i);
    }
    start = -1;
    for(int i = 1 ; i <= n ; ++i){
        if(arr[i] < 0){
            start = i;
            break;
        }
    }
    if(start == -1){
        printf("0\n");
        return 0;
    }
    int last = -1;
    for(int i = start ; i <= n ; ++i){
        if(arr[i] < 0){
            --k;
            last = i + 1;
        }
        else{
            if(i == n){
                ans += 1;
                v.emplace_back(-1 , n - last + 1);
            }
            else if(arr[i + 1] < 0){
                ans += 2;
                v.emplace_back(-2 , i - last + 1);
            }
        }
    }
    if(k < 0){
        printf("-1\n");
        return 0;
    }
    sort(v.begin() , v.end());
    for(auto it : v){
        if(it.second <= k){
            ans += it.first;
            k -= it.second;
        }
    }
    printf("%d\n" , ans + 1);
}