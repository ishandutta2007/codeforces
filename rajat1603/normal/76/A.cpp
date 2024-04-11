#include "bits/stdc++.h"
using namespace std;
const int N = 205;
const int M = 5e4 + 4;
int n , m;
long long g , s;
pair < pair < int , int > , pair < int , int > > arr[M];
long long ans = 1LL << 62;
set < pair < int , pair < int , int > > > ss;
int parent[N];
int cnt;
int lst;
int find(int node){
    if(parent[node] == node){
        return node;
    }
    return parent[node] = find(parent[node]);
}
bool join(int a , int b){
    if(find(a) == find(b)){
        return 0;
    }
    parent[find(b)] = find(a);
    return 1;
}
int main(){
    scanf("%d %d" , &n , &m);
    scanf("%lld %lld" , &g , &s);
    for(int i = 1 ; i <= m ; ++i){
        scanf("%d %d %d %d" , &arr[i].second.first , &arr[i].second.second , &arr[i].first.first , &arr[i].first.second);
    }
    sort(arr + 1 , arr + 1 + m);
    for(int i = 1 ; i <= m ; ++i){
        ss.insert(make_pair(arr[i].first.second , arr[i].second));
        for(int i = 1 ; i <= n ; ++i){
            parent[i] = i;
        }
        cnt = n - 1;
        auto useless = *ss.begin();
        bool ok = 0;
        for(auto it : ss){
            if(join(it.second.first , it.second.second)){
                lst = it.first;
                --cnt;
            }
            else{
                useless = it;
                
assert(!ok);
                ok = 1;
            }
        }
        if(ok){
            ss.erase(useless);
        }
        if(!cnt){
            ans = min(ans , arr[i].first.first * g + lst * s);
        }
    }
    if(ans == (1LL << 62)){
        ans = -1;
    }
    printf("%lld\n" , ans);
}