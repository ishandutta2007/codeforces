#include "bits/stdc++.h"
using namespace std;
const int N = 1e3 + 9;
const int S = N * N;
int n , m , q;
int arr[S];
int rgt[S];
int dwn[S];
inline int convert(int r , int c){
    return r * (m + 2) + c;
}
int main(){
    scanf("%d %d %d" , &n , &m , &q);
    for(int i = 1 ; i <= n ; ++i){
        for(int j = 1 ; j <= m ; ++j){
            scanf("%d" , &arr[convert(i , j)]);
        }
    }
    for(int i = 0 ; i <= n ; ++i){
        for(int j = 0 ; j <= m ; ++j){
            dwn[convert(i , j)] = convert(i + 1 , j);
            rgt[convert(i , j)] = convert(i , j + 1);
        }
    }
    while(q--){
        int x1 , y1 , x2 , y2 , r , c;
        scanf("%d %d %d %d %d %d" , &x1 , &y1 , &x2 , &y2 , &r , &c);
        int cell1 = convert(x1 , 0);
        int cell2 = convert(x2 , 0);
        int cell3 = convert(0 , y1);
        int cell4 = convert(0 , y2);
        for(int i = 1 ; i < y1 ; ++i){
            cell1 = rgt[cell1];
        }
        for(int i = 1 ; i < y2 ; ++i){
            cell2 = rgt[cell2];
        }
        for(int i = 1 ; i < x1 ; ++i){
            cell3 = dwn[cell3];
        }
        for(int i = 1 ; i < x2 ; ++i){
            cell4 = dwn[cell4];
        }
        for(int i = 0 ; i < r ; ++i){
            swap(rgt[cell1] , rgt[cell2]);
            if(i + 1 < r){
                cell1 = dwn[cell1];
                cell2 = dwn[cell2];
            }
            else{
                cell1 = rgt[cell1];
                cell2 = rgt[cell2];
            }
        }
        for(int i = 0 ; i < c ; ++i){
            swap(dwn[cell1] , dwn[cell2]);
            cell1 = rgt[cell1];
            cell2 = rgt[cell2];
        }
        for(int i = 0 ; i < c ; ++i){
            swap(dwn[cell3] , dwn[cell4]);
            if(i + 1 < c){
                cell3 = rgt[cell3];
                cell4 = rgt[cell4];
            }
            else{
                cell3 = dwn[cell3];
                cell4 = dwn[cell4];
            }
        }
        for(int i = 0 ; i < r ; ++i){
            swap(rgt[cell3] , rgt[cell4]);
            cell3 = dwn[cell3];
            cell4 = dwn[cell4];
        }
    }
    for(int i = 1 ; i <= n ; ++i){
        int cell = convert(i , 0);
        for(int j = 1 ; j <= m ; ++j){
            cell = rgt[cell];
            printf("%d%c" , arr[cell] , " \n"[j == m]);
        }
    }
}