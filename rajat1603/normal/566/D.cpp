#include "bits/stdc++.h"
using namespace std;
const int N = 2e5 + 5;
int n , q;
int nxt[N];
int parent[N];
int type;
int l;
int r;
int find(int a){
    if(parent[a] == a){
        return a;
    }
    return parent[a] = find(parent[a]);
}
void join(int a , int b){
    int x = find(a);
    int y = find(b);
    parent[y] = x;
}
int main(){
    scanf("%d %d" , &n , &q);
    for(int i = 1 ; i <= n ; ++i){
        nxt[i] = i + 1;
        parent[i] = i;
    }
    while(q--){
        scanf("%d %d %d" , &type , &l , &r);
        if(type == 1){
            join(l , r);
        }
        else if(type == 2){
            int idx = l;
            while(idx < r){
                join(idx , idx + 1);
                int temp = nxt[idx];
                nxt[idx] = r;
                idx = temp;
            }
        }
        else{
            int a = find(l);
            int b = find(r);
            if(a == b){
                printf("YES\n");
            }
            else{
                printf("NO\n");
            }
        }
    }
}