#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
int n;
int cnt[N];
int ans;
int inp;
int main(){
    scanf("%d" , &n);
    memset(cnt , 0 , sizeof(cnt));
    ans = 1;
    while(n--){
        scanf("%d" , &inp);
        ++cnt[inp];
    }
    for(int i = 2 ; i < N ; ++i){
        int sum = 0;
        for(int j = i ; j < N ; j += i){
            sum += cnt[j];
        }
        ans = max(ans , sum);
    }
    printf("%d\n" , ans);
}