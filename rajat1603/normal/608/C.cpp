#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
int n;
pair < int , int > arr[N];
int val[N];
int ans = 0;
set < pair < int , int > > s;
int main(){
    scanf("%d" , &n);
    for(int i = 1 ; i <= n ; ++i){
        scanf("%d %d" , &arr[i].first , &arr[i].second);
    }
    sort(arr + 1 , arr + 1 + n);
    val[0] = 0;
    val[1] = 1;
    s.insert(make_pair(arr[1].first , 1));
    for(int i = 2 ; i <= n ; ++i){
        auto it = s.lower_bound(make_pair(arr[i].first - arr[i].second , -1));
        if(it != s.begin()){
            val[i] = val[prev(it) -> second] + 1;
        }
        else{
            val[i] = 1;
        }
        s.insert(make_pair(arr[i].first , i));
    }
    for(int i = 0 ; i <= n ; ++i){
        ans = max(ans , val[i] + 1);
    }
    printf("%d\n" , n + 1 - ans);
}