#include "bits/stdc++.h"
using namespace std;
const int N = 1e6 + 6;
const int mod = 1e9 + 7;
const int D = 10;
int phi[N];
int fac[N];
int inv[N];
int ncr[N];
int spf[N];
int cnt[N];
int n , k , q;
int val;
int ans;
void init(){
    for(int i = 0 ; i < N ; ++i){
        phi[i] = i;
    }
    for(int i = 2 ; i < N ; ++i){
        if(phi[i] == i){
            for(int j = i ; j < N ; j += i){
                phi[j] = (phi[j] / i) * (i - 1);
            }
        }
    }
    fac[0] = 1;
    for(int i = 1 ; i < N ; ++i){
        fac[i] = (1LL * fac[i - 1] * i) % mod;
    }
    inv[N - 1] = 81818608;
    for(int i = N - 2 ; i >= 0 ; --i){
        inv[i] = (inv[i + 1] * (i + 1LL)) % mod;
    }
    for(int i = k ; i < N ; ++i){
        ncr[i] = (((1LL * fac[i] * inv[k]) % mod) * inv[i - k]) % mod;
    }
    for(int i = N - 1 ; i >= 1 ; --i){
        ncr[i] -= ncr[i - 1];
        ncr[i] += (ncr[i] < 0) * mod;
    }
    for(int i = 2 ; i * i < N ; ++i){
        if(!spf[i]){
            for(int j = i * i ; j < N ; j += i){
                spf[j] += (!spf[j]) * i;
            }
        }
    }
    for(int i = 1 ; i < N ; ++i){
        spf[i] += (!spf[i]) * i;
    }
}
pair < int , int > arr[D];
int siz;
void go(int pos , int num){
    if(pos > siz){
        ++cnt[num];
        ans += (1LL * ncr[cnt[num]] * phi[num]) % mod;
        ans -= (ans >= mod) * mod;
    }
    else{
        int cur = 1;
        for(int i = 0 ; i <= arr[pos].second ; ++i){
            go(pos + 1 , num * cur);
            cur *= arr[pos].first;
        }
    }
}
void insert(int val){
    siz = 0;
    arr[0] = make_pair(-1 , -1);
    while(val > 1){
        int tmp = spf[val];
        if(arr[siz].first != tmp){
            arr[++siz] = make_pair(tmp , 0);
        }
        ++arr[siz].second;
        val /= tmp;
    }
    go(1 , 1);
}
int main(){
    scanf("%d %d %d" , &n , &k , &q);
    init();
    while(n--){
        scanf("%d" , &val);
        insert(val);
    }
    while(q--){
        scanf("%d" , &val);
        insert(val);
        printf("%d\n" , ans);
    }
}