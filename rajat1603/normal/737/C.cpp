#include "bits/stdc++.h"
using namespace std;
const int N = 2e5 + 5;
int n , s;
int arr[N];
int inp[N];
vector < int > v;
int mx;
bool there[N];
int cnt[N];
int ans;
int empty[N];
int extra[N];
void solve(int i){
    int tot = cnt[mx] - cnt[i];
    int tmp = 0;
    tmp += tot;
    int emp = empty[i];
    emp -= tot;
    if(emp > 0){
        if(extra[i] >= emp){
            tmp += emp;
        }
        else{
            tmp = 1e9;
        }
    }
    ans = min(ans , tmp);
}
int main(){
    scanf("%d %d" , &n , &s);
    for(int i = 1 ; i <= n ; ++i){
        scanf("%d" , arr + i);
    }
    for(int i = 1 ; i <= n ; ++i){
        inp[i] = arr[i];
    }
    if(arr[s] != 0){
        arr[s] = 0;
    }
    v.clear();
    mx = 0;
    for(int i = 1 ; i <= n ; ++i){
        mx = max(mx , arr[i]);
    }
    memset(there , 0 , sizeof(there));
    for(int i = 1 ; i <= n ; ++i){
        there[arr[i]] = 1;
    }
    for(int i = 0 ; i < mx ; ++i){
        if(!there[i]){
            v.push_back(i);
        }
    }
    reverse(v.begin() , v.end());
    for(int i = 1 ; i <= n ; ++i){
        if(i != s){
            if(arr[i] == 0){
                if(v.empty()){
                    arr[i] = 1;
                }
                else{
                    arr[i] = v.back();
                    v.pop_back();
                }
            }
        }
    }
    mx = 0;
    memset(cnt , 0 , sizeof(cnt));
    ans = 1e9;
    for(int i = 1 ; i <= n ; ++i){
        mx = max(mx , arr[i]);
        ++cnt[arr[i]];
    }
    for(int i = 1 ; i <= mx ; ++i){
        cnt[i] += cnt[i - 1];
    }
    empty[0] = 0;
    for(int i = 1 ; i <= mx ; ++i){
        empty[i] = empty[i - 1];
        if(cnt[i] == cnt[i - 1]){
            ++empty[i];
        }
    }
    extra[0] = 0;
    for(int i = 1 ; i <= mx ; ++i){
        extra[i] = extra[i - 1];
        if(cnt[i] - cnt[i - 1] > 1){
            extra[i] += cnt[i] - cnt[i - 1] - 1;
        }
    }
    for(int i = 1 ; i <= mx ; ++i){
        solve(i);
    }
    if(n == 1){
        ans = 0;
    }
    for(int i = 1 ; i <= n ; ++i){
        ans += (inp[i] != arr[i]);
    }
    printf("%d\n" , ans);
}