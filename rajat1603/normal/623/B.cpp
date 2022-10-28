#include "bits/stdc++.h"
using namespace std;
const int N = 1e6 + 6;
int n;
long long a , b;
int arr[N];
long long ans;
int _g = 0;
long long change[N];
long long suffix[N];
long long sufmin[N];
long long get(int val){
    memset(change , 0 , sizeof(change));
    int lft = n + 1;
    int rgt = 1;
    memset(suffix , 0 , sizeof(suffix));
    for(int i = 2 ; i <= n ; ++i){
        if(arr[i] % val != 0){
            change[i] = 1;
            suffix[i] = 1;
            if(!((arr[i] % val == 1) || (arr[i] % val == (val - 1)))){
                lft = min(lft , i);
                rgt = max(rgt , i);
                change[i] = 0;
                suffix[i] = 0;
            }
        }
    }
    for(int i = 2 ; i <= n ; ++i){
        change[i] += change[i - 1];
    }
    for(int i = n - 1 ; i > 1 ; --i){
        suffix[i] += suffix[i + 1];
    }
    for(int i = 1 ; i <= n ; ++i){
        change[i] *= b;
        change[i] -= a * i;
        suffix[i] *= b;
        suffix[i] += a * i;
    }
    suffix[n + 1] = a * (n + 1LL);
    sufmin[n + 1] = suffix[n + 1];
    for(int i = n ; i >= 2 ; --i){
        sufmin[i] = min(sufmin[i + 1] , suffix[i]);
    }
    long long ret = (n - 1LL) * a;
    for(int i = 1 ; i <= n ; ++i){
        if(i < lft){
            ret = min(ret , change[i] + sufmin[max(rgt + 1 , i + 1)] - a);
        }
    }
    return ret;
}
long long solve(int val){
    long long ret = 1LL << 60;
    int tmp = val;
    for(int i = 2 ; i * i <= tmp ; ++i){
        bool b = 0;
        while(tmp % i == 0){
            b = 1;
            tmp /= i;
        }
        if(b){
            ret = min(ret , get(i));
        }
    }
    if(tmp > 1){
        ret = min(ret , get(tmp));
    }
    return ret;
}
int main(){
    scanf("%d %lld %lld" , &n , &a , &b);
    for(int i = 1 ; i <= n ; ++i){
        scanf("%d" , &arr[i]);
        _g = __gcd(_g , arr[i]);
    }
    if(_g > 1){
        printf("0\n");
        return 0;
    }
    ans = 1LL * a * (n - 1LL);
    ans = min(ans , solve(arr[1] + 1) + b);
    ans = min(ans , solve(arr[1] - 1) + b);
    ans = min(ans , solve(arr[1]));
    reverse(arr + 1 , arr + 1 + n);
    ans = min(ans , solve(arr[1] + 1) + b);
    ans = min(ans , solve(arr[1] - 1) + b);
    ans = min(ans , solve(arr[1]));
    cout << ans;
}