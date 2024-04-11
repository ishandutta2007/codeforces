#include "bits/stdc++.h"
using namespace std;
const int N = 128;
int m , n;
double arr[N];
struct matrix{
    double arr[N][N];
    matrix operator * (const matrix &other) const {
        matrix res;
        for(int i = 0 ; i < N ; ++i){
            for(int j = 0 ; j < N ; ++j){
                res.arr[i][j] = 0;
                for(int k = 0 ; k < N ; ++k){
                    res.arr[i][j] += arr[i][k] * other.arr[k][j];
                }
            }
        }
        return res;
    }
};
matrix base;
matrix power(matrix a , int b){
    matrix res;
    for(int i = 0 ; i < N ; ++i){
        for(int j = 0 ; j < N ; ++j){
            res.arr[i][j] = 0;
        }
        res.arr[i][i] = 1;
    }
    while(b){
        if(b & 1){
            res = res * a;
        }
        a = a * a;
        b >>= 1;
    }
    return res;
}
int main(){
    scanf("%d %d" , &m , &n);
    for(int i = 0 ; i <= n ; ++i){
        scanf("%lf" , arr + i);
    }
    for(int i = 0 ; i < N ; ++i){
        for(int j = 0 ; j < N ; ++j){
            base.arr[i][j] = 0;
        }
    }
    for(int i = 0 ; i < N ; ++i){
        for(int j = 0 ; j <= n ; ++j){
            base.arr[i][i ^ j] += arr[j];
        }
    }
    base = power(base , m);
    printf("%.6lf\n" , 1.0 - base.arr[0][0]);
}