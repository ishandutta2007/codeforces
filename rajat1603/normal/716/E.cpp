#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
int n , mod;
int a , b , c;
vector < pair < int , int > > v[N];
int pw01;
long long ans;
int phi(int n){
    int res = n;
    for(int i = 2 ; i * i <= n ; ++i){
        if(n % i == 0){
            res /= i;
            res *= i - 1;
            while(n % i == 0){
                n /= i;
            }
        }
    }
    if(n > 1){
        res /= n;
        res *= n - 1;
    }
    return res;
}
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
bool done[N];
int subtree[N];
void dfs1(int node , int parent){
    subtree[node] = 1;
    for(auto it : v[node]){
        if(it.first != parent && !done[it.first]){
            dfs1(it.first , node);
            subtree[node] += subtree[it.first]; 
        }
    }
}
int find(int node , int parent , int val){
    for(auto it : v[node]){
        if(it.first != parent && !done[it.first] && subtree[it.first] > val){
            return find(it.first , node , val); 
        }
    }
    return node;
}
map < int , int > mp;
void dfs2(int node , int parent , int len , int num){
    ans += mp[num];
    len = (10LL * len) % mod;
    for(auto it : v[node]){
        if(it.first != parent && !done[it.first]){
            dfs2(it.first , node , len , (num + 1LL * len * it.second) % mod);
        }
    }
}
void dfs3(int node , int parent , int len , int num){
    len = (1LL * len * pw01) % mod;
    ++mp[(1LL * (mod - num) * len) % mod];
    for(auto it : v[node]){
        if(it.first != parent && !done[it.first]){
            dfs3(it.first , node , len , (num * 10LL + it.second) % mod);
        }
    }
}
int calc(int node){
    mp.clear();
    mp[0] = 1;
    for(auto it : v[node]){
        if(!done[it.first]){
            dfs2(it.first , node , 1 , it.second);
            dfs3(it.first , node , 1 , it.second);
        }
    }
    mp.clear();
    reverse(v[node].begin() , v[node].end());
    for(auto it : v[node]){
        if(!done[it.first]){
            dfs2(it.first , node , 1 , it.second);
            dfs3(it.first , node , 1 , it.second);
        }
    }
    ans += mp[0];
}
int solve(int node){
    dfs1(node , 0);
    int cent = find(node , 0 , subtree[node] >> 1);
    calc(cent);
    done[cent] = 1;
    for(auto it : v[cent]){
        if(!done[it.first]){
            solve(it.first);
        }
    }
}
int main(){
    scanf("%d %d" , &n , &mod);
    if(mod == 1){
        printf("%lld\n" , 1LL * n * (n - 1LL));
        return 0;
    }
    pw01 = power(10 , phi(mod) - 1);
    for(int i = 1 ; i < n ; ++i){
        scanf("%d %d %d" , &a , &b , &c);
        c %= mod;
        v[a + 1].emplace_back(make_pair(b + 1 , c));
        v[b + 1].emplace_back(make_pair(a + 1 , c));
    }
    solve(1);
    printf("%lld\n" , ans);
}