#include "bits/stdc++.h"
using namespace std;
const int N = 1e6 + 6;
const int M = 1e7 + 7;
int n , m , k;
int f[N];
pair < int , int > s[M];
int nxt[M];
int cnt[M];
bool check(int idx){
    for(int i = 1 ; i <= idx ; ++i){
        ++cnt[s[i].first];
    }
    long long avail = 0;
    int last = -1;
    bool rekt = 0;
    for(int i = 0 ; i < M ; i = nxt[i]){
        avail += 1LL * (i - last) * k;
        last = i;
        if(cnt[i] > avail){
            rekt = 1;
            break;
        }
        avail -= cnt[i];
    }
    for(int i = 1 ; i <= idx ; ++i){
        --cnt[s[i].first];
    }
    return !rekt;
}
int main(){
    scanf("%d %d %d" , &n , &m , &k);
    for(int i = 0 ; i < M ; ++i){
        nxt[i] = M;
    }
    for(int i = 1 ; i <= n ; ++i){
        scanf("%d" , f + i);
        ++cnt[f[i]];
        if(f[i]){
            nxt[f[i] - 1] = f[i];
        }
    }
    for(int i = 1 ; i <= m ; ++i){
        scanf("%d" , &s[i].first);
        s[i].second = i;
        if(s[i].first){
            nxt[s[i].first - 1] = s[i].first;
        }
    }
    sort(s + 1 , s + 1 + m);
    reverse(s + 1 , s + 1 + m);
    for(int i = M - 2 ; i >= 0 ; --i){
        nxt[i] = min(nxt[i] , nxt[i + 1]);
    }
    if(check(0)){
        int l = 0;
        int r = m;
        while(l < r){
            int mid = l + r + 1 >> 1;
            if(check(mid)){
                l = mid;
            }
            else{
                r = mid - 1;
            }
        }
        printf("%d\n" , l);
        for(int i = 1 ; i <= l ; ++i){
            printf("%d " , s[i].second);
        }
        printf("\n");
    }
    else{
        printf("-1\n");
    }
}