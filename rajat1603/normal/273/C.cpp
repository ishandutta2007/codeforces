#include "bits/stdc++.h"
using namespace std;
const int N = 3e5 + 5;
int n , m;
int a , b;
vector < int > v[N];
char str[N];
int deg[N];
void put(int node , char where){
    str[node] = where;
    int rekt = 0;
    for(int next : v[node]){
        if(str[next] == where){
            ++deg[next];
            if(deg[next] > 1){
                rekt = next;
            }
            ++deg[node];
        }
    }
    if(rekt){
        for(int next : v[rekt]){
            if(str[next] == where){
                --deg[next];
            }
        }
        deg[rekt] = 0;
        put(rekt , where ^ 1);
    }
}
int main(){
    scanf("%d %d" , &n , &m);
    for(int i = 1 ; i <= m ; ++i){
        scanf("%d %d" , &a , &b);
        v[a].emplace_back(b);
        v[b].emplace_back(a);
    }
    for(int i = 1 ; i <= n ; ++i){
        str[i] = '$';
    }
    for(int i = 1 ; i <= n ; ++i){
        int cnt0 = 0;
        int cnt1 = 0;
        for(int j : v[i]){
            if(j < i){
                if(str[j] == '0'){
                    ++cnt0;
                }
                else{
                    ++cnt1;
                }
            }
        }
        if(cnt0 <= cnt1){
            put(i , '0');
        }
        else{
            put(i , '1');
        }
    }
    printf("%s" , str + 1);
}