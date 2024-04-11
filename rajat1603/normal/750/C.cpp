#include "bits/stdc++.h"
using namespace std;
const int N = 2e5 + 5;
const int inf = 1e9 + 7;
const int inf2 = 1e9 - 1e8;
int n;
int val[N];
int di[N];
int l;
int r;
bool ok;
int main(){
    cin >> n;
    ok = 0;
    for(int i = 1 ; i <= n ; ++i){
        cin >> val[i] >> di[i];
        if(di[i] == 2){
            ok = 1;
        }
    }
    if(di[1] == 1){
        l = 1900;
        r = inf;
    }
    else{
        l = -inf;
        r = 1899;
    }
    for(int i = 1 ; i <= n ; ++i){
        if(di[i] == 1){
            l = max(l , 1900);
        }
        else{
            r = min(r , 1899);
        }
        l += val[i];
        r += val[i];
    }
    if(r >= inf2){
        printf("Infinity\n");
    }
    else if(r < l){
        printf("Impossible\n");
    }
    else{
        printf("%d\n" , r);
    }
}