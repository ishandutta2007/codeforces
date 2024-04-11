#include "bits/stdc++.h"
using namespace std;
const int N = 505;
int n;
int arr[N];
vector < int > v;
long long ans;
void solve(int val){
    long long res = 0;
    for(int i = 1 ; i <= n ; ++i){
        if(val > arr[i]){
            return;
        }
        int tmp = (arr[i] / (val + 1)) + 1;
        if(arr[i] / tmp != val){
            tmp = ans + 1;
        }
        if(arr[i] % (val + 1) == 0){
            tmp = min(tmp , arr[i] / (val + 1));
        }
        res += tmp;
    }
    ans = min(ans , res);
}
int main(){
    scanf("%d" , &n);
    for(int i = 1 ; i <= n ; ++i){
        scanf("%d" , arr + i);
    }
    sort(arr + 1 , arr + 1 + n);
    v.clear();
    for(int i = 1 ; i * i <= arr[1] ; ++i){
        v.emplace_back(i);
        v.emplace_back(i + 1);
        if(i > 1){
            v.emplace_back(i - 1);
        }
        v.emplace_back(arr[1] / i);
        v.emplace_back(arr[1] / i + 1);
        v.emplace_back(arr[1] / i - 1);
    }
    sort(v.begin() , v.end());
    v.resize(unique(v.begin() , v.end()) - v.begin());
    ans = 1LL << 60;
    for(auto it : v){
        solve(it);
    }
    printf("%lld\n" , ans);
}