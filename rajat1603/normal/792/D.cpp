#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
long long n;
int q;
long long u;
char str[N];
pair < long long , long long > path[N];
int siz;
void go(long long l , long long r , int pos){
    if(path[siz] != make_pair(l , r)){
        path[++siz] = {l , r};
    }
    long long mid = l + r >> 1;
    if(str[pos]){
        if(str[pos] == 'L'){
            if(l == r){
                go(l , r , pos + 1);
            }
            else{
                go(l , mid - 1 , pos + 1);
            }
        }
        else if(str[pos] == 'R'){
            if(l == r){
                go(l , r , pos + 1);
            }
            else{
                go(mid + 1 , r , pos + 1);
            }
        }
        else{
            if(l == 1 && r == n){
                go(l , r , pos + 1);
            }
            else{
                --siz;
                go(path[siz].first , path[siz].second , pos + 1);
            }
        }
    }
    else{
        printf("%lld\n" , mid);
    }
}
void find(long long l , long long r , long long node){
    long long mid = l + r >> 1;
    if(node == mid){
        go(l , r , 0);
    }
    else if(node < mid){
        path[++siz] = {l , r};
        find(l , mid - 1 , node);
    }
    else{
        path[++siz] = {l , r};
        find(mid + 1 , r , node);
    }
}
int main(){
    scanf("%lld %d" , &n , &q);
    while(q--){
        scanf("%lld %s" , &u , str);
        siz = 0;
        find(1 , n , u);
    }
}