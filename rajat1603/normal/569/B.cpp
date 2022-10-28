#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
int n;
int inp;
bool mark[N];
int cur = 1;
int ans[N];
int main(){
    scanf("%d" , &n);
    for(int i = 1 ; i <= n ; ++i){
        scanf("%d" , &inp);
        if(inp <= n && !mark[inp]){
            ans[i] = inp;
            mark[inp] = 1;
        }
    }
    for(int i = 1 ; i <= n ; ++i){
        if(!ans[i]){
            while(mark[cur]){
                ++cur;
            }
            ans[i] = cur++;
        }
        printf("%d " , ans[i]);
    }
}