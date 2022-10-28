#include "bits/stdc++.h"
using namespace std;
const int N = 2e5 + 5;
int n , m;
int p[N];
int s[N];
set < pair < int , int > > ss;
pair < int , int > pp[N];
int a[N];
int b[N];
int ansc , ansu;
int get(int s , int p){
    int ret = 0;
    while(s != p){
        s = s + 1 >> 1;
        ++ret;
    }
    return ret;
}
int main(){
    scanf("%d %d" , &n , &m);
    for(int i = 1 ; i <= n ; ++i){
        scanf("%d" , p + i);
    }
    for(int i = 1 ; i <= m ; ++i){
        scanf("%d" , s + i);
    }
    for(int i = 1 ; i <= n ; ++i){
        b[i] = 0;   
    }
    for(int i = 1 ; i <= m ; ++i){
        a[i] = 0;
    }
    ss.clear();
    for(int i = 1 ; i <= n ; ++i){
        pp[i] = make_pair(p[i] , i);
    }
    sort(pp + 1 , pp + 1 + n);
    for(int i = 1 ; i <= m ; ++i){
        ss.insert(make_pair(s[i] , i));
    }
    for(int i = n ; i >= 1 ; --i){
        int x = pp[i].first;
        int l = x;
        int r = x;
        while(l <= 1e9){
            auto it1 = ss.lower_bound(make_pair(l , 0));
            if(it1 != ss.end() && it1 -> first <= r){
                b[pp[i].second] = it1 -> second;
                ss.erase(it1);
                break;
            }
            if(l == 1){
                l = 2;
                r = 2;
            }
            else{
                l += l - 1;
                r += r;
            }
        }
    }
    for(int i = 1 ; i <= n ; ++i){
        if(b[i]){
            a[b[i]] = get(s[b[i]] , p[i]);
        }
    }
    ansc = 0;
    ansu = 0;
    for(int i = 1 ; i <= n ; ++i){
        if(b[i]){
            ++ansc;
        }
    }
    for(int i = 1 ; i <= m ; ++i){
        ansu += a[i];
    }
    printf("%d %d\n" , ansc , ansu);
    for(int i = 1 ; i <= m ; ++i){
        printf("%d%c" , a[i] , " \n"[i == m]);
    }
    for(int i = 1 ; i <= n ; ++i){
        printf("%d%c" , b[i] , " \n"[i == n]);
    }
}