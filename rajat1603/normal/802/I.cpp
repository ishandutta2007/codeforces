#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
const int LN = 18;
int t;
char str[N];
int n;
int sa[LN][N];
int arr[N];
int lcp[N];
pair < pair < int , int > , int > tmp[N];
void buildsa(){
    for(int i = 1 ; i <= n ; ++i){
        sa[0][i] = str[i] - 'a' + 1;
    }
    for(int i = 1 ; i < LN ; ++i){
        for(int j = 1 ; j <= n ; ++j){
            int x = j + (1 << (i - 1));
            tmp[j] = {{sa[i - 1][j] , (x > n) ? -1 : sa[i - 1][x]} , j};
        }
        sort(tmp + 1 , tmp + 1 + n);
        sa[i][tmp[1].second] = 1;
        for(int j = 2 ; j <= n ; ++j){
            sa[i][tmp[j].second] = sa[i][tmp[j - 1].second] + (tmp[j].first != tmp[j - 1].first);
        }
    }
    for(int i = 1 ; i <= n ; ++i){
        arr[sa[LN - 1][i]] = i;
    }
    for(int i = 1 ; i < n ; ++i){
        int x = arr[i];
        int y = arr[i + 1];
        int res = 0;
        for(int j = LN - 1 ; j >= 0 ; --j){
            if(sa[j][x] == sa[j][y]){
                res += 1 << j;
                x += 1 << j;
                y += 1 << j;
            }
        }
        lcp[i] = res;
    }
    lcp[n] = 0;
}
int lft[N];
int rgt[N];
void solve(){
    scanf("%s" , str + 1);
    n = strlen(str + 1);
    buildsa();
    long long ans = 1LL * n * (n + 1LL);
    ans >>= 1;
    stack < int > s;
    while(!s.empty()){
        s.pop();
    }
    for(int i = 1 ; i < n ; ++i){
        while(!s.empty() && lcp[s.top()] >= lcp[i]){
            s.pop();
        }
        if(s.empty()){
            lft[i] = 1;
        }
        else{
            lft[i] = s.top() + 1;
        }
        s.push(i);
    }
    while(!s.empty()){
        s.pop();
    }
    for(int i = n - 1 ; i >= 1 ; --i){
        while(!s.empty() && lcp[s.top()] > lcp[i]){
            s.pop();
        }
        if(s.empty()){
            rgt[i] = n;
        }
        else{
            rgt[i] = s.top();
        }
        s.push(i);
    }
    for(int i = 1 ; i < n ; ++i){
        ans += 2LL * lcp[i] * (i - lft[i] + 1) * (rgt[i] - i);
    }
    printf("%lld\n" , ans);
}
int main(){
    scanf("%d" , &t);
    while(t--){
        solve();
    }
}