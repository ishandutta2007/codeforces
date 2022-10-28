#include "bits/stdc++.h"
using namespace std;
const int N = 105;
int n;
int x[4];
int y[4];
int a[4];
int b[4];
pair < int , int > cur[4];
pair < int , int > get(int x , int y , int a , int b){
    x -= a;
    y -= b;
    return make_pair(-y + a , x + b);
}
int sqr(int a){
    return a * a;
}
int dist(int i , int j){
    return sqr(cur[i].first - cur[j].first) + sqr(cur[i].second - cur[j].second);
}
bool ok(){
    sort(cur , cur + 4);
    for(int j = 0 ; j < 3 ; ++j){
        if(cur[j] == cur[j + 1]){
            return 0;
        }
    }
    if(dist(0 , 3) != dist(1 , 2)){
        return 0;
    }
    if(dist(0 , 1) != dist(1 , 3) || dist(1 , 3) != dist(3 , 2) || dist(2 , 3) != dist(0 , 2) || dist(0 , 2) != dist(0 , 1)){
        return 0;
    }
    return 1;
}
int solve(){
    int ans = 20;
    for(int i = 0 ; i < 256 ; ++i){
        int _i = i;
        int sum = 0;
        for(int j = 0 ; j < 8 ; j += 2){
            int tmp = i & 3;
            sum += tmp;
            cur[j >> 1] = make_pair(x[j >> 1] , y[j >> 1]);
            while(tmp--){
                cur[j >> 1] = get(cur[j >> 1].first , cur[j >> 1].second , a[j >> 1] , b[j >> 1]);
            }
            i >>= 2;
        }
        if(ok()){
            ans = min(ans , sum);
        }
        i = _i;
    }
    if(ans == 20){
        ans = -1;
    }
    return ans;
}
int main(){
    scanf("%d" , &n);
    while(n--){
        for(int j = 0 ; j < 4 ; ++j){
            scanf("%d %d %d %d" , x + j , y + j , a + j , b + j);
        }
        printf("%d\n" , solve());
    }
}