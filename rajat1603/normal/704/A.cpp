#include "bits/stdc++.h"
using namespace std;
const int N = 3e5 + 5;
int n , q;
int lastt[N];
int tt;
int cur;
int type[N] , a[N];
int tot[N];
vector < int > v;
int main(){
    scanf("%d %d" , &n , &q);
    cur = 0;
    tt = 0;
    v.clear();
    for(int i = 1 ; i <= q ; ++i){
        scanf("%d" , type + i);
        if(type[i] == 1){
            scanf("%d" , a + i);
            ++cur;
            ++tot[a[i]];
            v.emplace_back(i);
        }
        else if(type[i] == 2){
            scanf("%d" , a + i);
            cur -= tot[a[i]];
            tot[a[i]] = 0;
            lastt[a[i]] = i;
        }
        else{
            scanf("%d" , a + i);
            for(int j = tt ; j < a[i] ; ++j){
                if(lastt[a[v[j]]] <= v[j]){
                    --cur;
                    --tot[a[v[j]]];
                }
            }
            tt = max(tt , a[i]);
        }
        printf("%d\n" , cur);
    }
}