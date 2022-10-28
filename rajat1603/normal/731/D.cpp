#include "bits/stdc++.h"
using namespace std;
const int N = 1e6 + 6;
int n , c;
vector < int > v[N];
int sz;
int cnt[N + N];
void update(int l , int r , int val){
    if(r < 0){
        l += c;
        r += c;
    }
    if(l < 0){
        cnt[0] += val;
        cnt[r + 1] -= val;
        cnt[c + l] += val;
        cnt[c] -= val;
    }
    else{
        cnt[l] += val;
        cnt[r + 1] -= val;
    }
}
void solve2(int x , int y , int val){
    if(x < y){
        int lft = 1 - x;
        int rgt = c - y;
        update(lft , rgt , val);
    }
    else{
        cnt[0] += val;
        cnt[c] -= val;
        solve2(y , x , -val);
    }
}
void solve(int x , int y){
    int dif = -1;
    for(int i = 0 ; i < min(v[x].size() , v[y].size()) ; ++i){
        if(v[x][i] != v[y][i]){
            dif = i;
            break;
        }
    }
    if(dif == -1){
        if(v[x].size() <= v[y].size()){
            update(0 , c - 1 , 1);
        }
    }
    else{
        solve2(v[x][dif] , v[y][dif] , 1);
    }
}
int main(){
    scanf("%d %d" , &n , &c);
    for(int i = 1 ;  i <= n ; ++i){
        scanf("%d" , &sz);
        v[i].resize(sz);
        for(int j = 0 ; j < sz ; ++j){
            scanf("%d" , &v[i][j]);
        }
    }
    for(int i = 1 ; i < n ; ++i){
        solve(i , i + 1);
    }
    for(int i = 0 ; i < c ; ++i){
        cnt[i + 1] += cnt[i];
        if(cnt[i] == n - 1){
            printf("%d\n" , i);
            return 0;
        }
    }
    printf("-1\n");
}