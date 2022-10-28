#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
int n;
int l[N];
int r[N];
int lsum;
int rsum;
int ans;
int idx;
int solve(int i){
    int tmpl = lsum - l[i] + r[i];
    int tmpr = rsum - r[i] + l[i];
    return abs(tmpr - tmpl);
}
int main(){
    scanf("%d" , &n);
    for(int i = 1 ; i <= n ; ++i){
        scanf("%d %d" , l + i , r + i);
        lsum += l[i];
        rsum += r[i];
    }
    ans = abs(lsum - rsum);
    idx = 0;
    for(int i = 1 ; i <= n ; ++i){
        int tmp = solve(i);
        if(tmp > ans){
            ans = tmp;
            idx = i;
        }
    }
    printf("%d\n" , idx);
}