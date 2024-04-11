#include "bits/stdc++.h"
using namespace std;
const int N = 505;
int n;
int a[N];
int m;
int b[N];
vector < pair < int , char > > ans;
void rekt(){
    printf("NO\n");
    exit(0);
}
void solve(int l , int r , int add){
    if(r < l){
        rekt();
    }
    if(l == r){
        return;
    }
    int idx = -1;
    int val = -1;
    for(int i = l ; i <= r ; ++i){
        if(a[i] > val){
            if((i > l && a[i - 1] < a[i]) || (i < r && a[i + 1] < a[i])){
                idx = i;
                val = a[i];
            }
        }
    }
    if(idx == -1){
        rekt();
    }
    if(idx < r && a[idx + 1] < a[idx]){
        for(int i = idx + 1 ; i <= r ; ++i){
            ans.emplace_back(make_pair(add + idx - l + 1 , 'R'));
        }
        for(int i = idx ; i > l ; --i){
            ans.emplace_back(make_pair(add + i - l + 1 , 'L'));
        }
    }
    else{
        for(int i = idx ; i > l ; --i){
            ans.emplace_back(make_pair(add + i - l + 1 , 'L'));
        }
        for(int i = idx + 1 ; i <= r ; ++i){
            ans.emplace_back(make_pair(add + 1 , 'R'));
        }   
    }
}
int main(){
    cin >> n;
    for(int i = 1 ; i <= n ; ++i){
        cin >> a[i];
    }
    cin >> m;
    for(int i = 1 ; i <= m ; ++i){
        cin >> b[i];
    }
    int cur = 1;
    for(int i = 1 ; i <= m ; ++i){
        int sum = b[i];
        int start = cur;
        while(sum > 0){
            if(cur > n){
                rekt();
            }
            sum -= a[cur];
            ++cur;
        }
        if(sum < 0){
            rekt();
        }
        solve(start , cur - 1 , i - 1);
    }
    if(cur <= n){
        rekt();
    }
    printf("YES\n");
    for(auto it : ans){
        printf("%d %c\n" , it.first , it.second);
    }
}