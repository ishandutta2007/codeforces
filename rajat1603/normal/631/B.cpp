#include "bits/stdc++.h"
using namespace std;
const int N = 5e3 + 3;
int n , m , k;
int row[N];
int lstr[N];
int col[N];
int lstc[N];
int type , x , c;
int main(){
    scanf("%d %d %d" , &n , &m , &k);
    for(int i = 1 ; i <= k ; ++i){
        scanf("%d %d %d" , &type , &x , &c);
        if(type & 1){
            row[x] = c;
            lstr[x] = i;
        }
        else{
            col[x] = c;
            lstc[x] = i;
        }
    }
    for(int i = 1 ; i <= n ; ++i){
        for(int j = 1 ; j <= m ; ++j){
            if(lstr[i] > lstc[j]){
                printf("%d " , row[i]);
            }
            else{
                printf("%d " , col[j]);
            }
        }
        printf("\n");
    }
}