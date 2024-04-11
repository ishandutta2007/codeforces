#include "bits/stdc++.h"
using namespace std;
const int N = 2e5 + 5;
const int mod = 1e9 + 7;
const int MAX = 1e6 + 6;
const int SQN = 350;
int add(int a , int b){
    int res = a + b;
    if(res >= mod){
        return res - mod;
    }
    return res;
}
int mult(int a , int b){
    long long res = a;
    res *= b;
    if(res >= mod){
        return res % mod;
    }
    return res;
}
int power(int a , int b){
    int res = 1;
    while(b){
        if(b & 1){
            res = mult(res , a);
        }
        a = mult(a , a);
        b >>= 1;
    }
    return res;
}
int n;
int arr[N];
int spf[MAX];
int res[N];
int inv[MAX];
void pre(){
    for(int i = 1 ; i < MAX ; ++i){
        spf[i] = i;
    }
    for(int i = 2 ; i < MAX ; ++i){
        if(spf[i] == i){
            inv[i] = power(i , mod - 2);
            inv[i - 1] = power(i - 1 , mod - 2);
            for(int j = i ; j < MAX ; j += i){
                spf[j] = i;
            }
        }
    }
}
int q;
int l , r;
set < int > s[N];
vector < pair < int , int > > v[N];
int ans[N];
int lst[MAX];
int bit[N];
void update(int idx , int val){
    while(idx){
        bit[idx] = mult(bit[idx] , val);
        idx -= idx & -idx;
    }
}
int query(int idx){
    int res = 1;
    while(idx <= n){
        res = mult(res , bit[idx]);
        idx += idx & -idx;
    }
    return res;
}
int main(){
    pre();
    scanf("%d" , &n);
    for(int i = 1 ; i <= n ; ++i){
        scanf("%d" , &arr[i]);
        bit[i] = 1;
    }
    res[0] = 1;
    for(int i = 1 ; i <= n ; ++i){
        res[i] = mult(res[i - 1] , arr[i]);
    }
    for(int i = 1 ; i <= n ; ++i){
        set < int > temp;
        int ele = arr[i];
        while(ele > 1){
            temp.insert(spf[ele]);
            ele /= spf[ele];
        }
        s[i] = temp;
    }
    scanf("%d" , &q);
    for(int i = 1 ; i <= q ; ++i){
        scanf("%d %d" , &l , &r);
        ans[i] = mult(res[r] , power(res[l - 1] , mod - 2));
        v[r].emplace_back(make_pair(l , i));
    }
    for(int i = 1 ; i <= n ; ++i){
        for(int p : s[i]){
            update(lst[p] , p);
            update(lst[p] , inv[p - 1]);
            update(i , inv[p]);
            update(i , p - 1);
            lst[p] = i;
        }
        for(auto it : v[i]){
            ans[it.second] = mult(ans[it.second] , query(it.first));
        }
    }
    for(int i = 1 ; i <= q ; ++i){
        printf("%d\n" , ans[i]);
    }
}