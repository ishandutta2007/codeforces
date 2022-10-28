#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
int mod , n;
int arr[N];
int tmp[N];
int power(int a , int b){
    int res = 1;
    while(b){
        if(b & 1){
            res = (1LL * res * a) % mod;
        }
        a = (1LL * a * a) % mod;
        b >>= 1;
    }
    return res;
}
bool check(int start , int d){
    tmp[1] = start;
    for(int i = 2 ; i <= n ; ++i){
        tmp[i] = (tmp[i - 1] + d) % mod;
    }
    sort(tmp + 1 , tmp + 1 + n);
    for(int i = 1 ; i <= n ; ++i){
        if(tmp[i] != arr[i]){
            return 0;
        }
    }
    return 1;
}
pair < int , int > solve(){
    if(n == 0){
        return make_pair(0 , 1);
    }
    if(n == 1){
        return make_pair(arr[1] , 1);
    }
    if(n == 2){
        return make_pair(arr[1] , arr[2] - arr[1]);
    }
    if(n == mod){
        return make_pair(0 , 1);
    }
    vector < pair < int , int > > v1;
    vector < pair < int , int > > v2;
    for(int idx = 1 ; idx <= 2 ; ++idx){
        swap(arr[1] , arr[idx]);
        set < int > s;
        s.clear();
        for(int i = 2 ; i <= n ; ++i){
            s.insert((arr[1] + mod - arr[i]) % mod);
        }
        int cnt = 0;
        for(int i = 2 ; i <= n ; ++i){
            int val = arr[i] - arr[1] + mod;
            val %= mod; 
            if(s.find(val) != s.end()){
                s.erase(s.find(val));
                ++cnt;
            }
        }
        cnt >>= 1;
        v1.swap(v2);
        v1.emplace_back(make_pair(arr[1] , cnt + 1));
        v1.emplace_back(make_pair(arr[1] , n - cnt));
        swap(arr[1] , arr[idx]);
    }
    for(auto it1 : v1){
        for(auto it2 : v2){
            int a = it1.first;
            int b = it2.first;
            int p1 = it1.second;
            int p2 = it2.second;
            if(p1 == p2){
                continue;
            }
            if(p1 > p2){
                swap(a , b);
                swap(p1 , p2);
            }
            int d = (1LL * ((b - a + mod) % mod) * power(p2 - p1 , mod - 2)) % mod;
            int start = (a - ((1LL * (p1 - 1LL) * d) % mod) + mod) % mod;
            if(check(start , d)){
                return make_pair(start , d);
            }
        }
    }
    return make_pair(-1 , -1);
}
int main(){
    scanf("%d %d" , &mod , &n);
    for(int i = 1 ; i <= n ; ++i){
        scanf("%d" , arr + i);
    }
    sort(arr + 1 , arr + 1 + n);
    if(n + n > mod){
        set < int > s;
        s.clear();
        for(int i = 0 ; i < mod ; ++i){
            s.insert(i);
        }
        for(int i = 1 ; i <= n ; ++i){
            s.erase(arr[i]);
        }
        n = 0;
        for(auto it : s){
            arr[++n] = it;
        }
        auto it = solve();
        if(it.first != -1){
            it.first += (1LL * it.second * n) % mod;
            it.first %= mod;
        }
        if(it.first == -1){
            printf("-1\n");
        }
        else{
            printf("%d %d\n" , it.first , it.second);
        }
        return 0;
    }
    auto it = solve();
    if(it.first == -1){
        printf("-1\n");
    }
    else{
        printf("%d %d\n" , it.first , it.second);
    }
}