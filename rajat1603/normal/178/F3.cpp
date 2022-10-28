#include "bits/stdc++.h"
using namespace std;
const int N = 2e3 + 3;
int n , k;
string str[N];
char tmp[N];
int lcp[N];
int getlcp(string &a , string &b){
    int len = 0;
    for(int i = 0 ; i < min(a.size() , b.size()) ; ++i){
        if(a[i] != b[i]){
            break;
        }
        ++len;
    }
    return len;
}
vector < int > solve(int l , int r){
    if(r <= l){
        return vector < int > (k + 1 , 0);
    }
    int val = 1e9;
    int idx = -1;
    for(int i = l ; i < r ; ++i){
        if(lcp[i] < val){
            val = lcp[i];
            idx = i;
        }
    }
    auto L = solve(l , idx);
    auto R = solve(idx + 1 , r);
    vector < int > res(k + 1 , 0);
    for(int x = 0 ; x <= min(k , idx - l + 1) ; ++x){
        for(int y = 0 ; y + x <= k && y <= (r - idx) ; ++y){
            res[x + y] = max(res[x + y] , L[x] + R[y] + val * x * y);
        }
    }
    return res;
}
int main(){
    scanf("%d %d" , &n , &k);
    for(int i = 1 ; i <= n ; ++i){
        scanf("%s" , tmp);
        str[i] = tmp;
    }
    sort(str + 1 , str + 1 + n);
    for(int i = 1 ; i < n ; ++i){
        lcp[i] = getlcp(str[i] , str[i + 1]);
    }
    printf("%d\n" , solve(1 , n)[k]);
}