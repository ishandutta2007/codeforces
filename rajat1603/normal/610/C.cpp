#include "bits/stdc++.h"
using namespace std;
const int N = 1e3;
int n;
char arr[N][N];
int main(){
    cin >> n;
    arr[0][0] = '+';
    for(int i = 1 ; i <= n ; ++i){
        int p1 = 1 << i;
        int p2 = p1 >> 1;
        for(int j = 0 ; j < p2 ; ++j){
            for(int k = p2 ; k < p1 ; ++k){
                arr[j][k] = arr[j][k - p2];
            }
        }
        for(int j = p2 ; j < p1 ; ++j){
            for(int k = 0 ; k < p2 ; ++k){
                arr[j][k] = arr[j - p2][k];
            }
            for(int k = p2 ; k < p1 ; ++k){
                if(arr[j - p2][k - p2] == '+'){
                    arr[j][k] = '*';
                }
                else{
                    arr[j][k] = '+';
                }
            }
        }
    }
    for(int i = 0 ; i < (1 << n) ; ++i){
        printf("%s\n" , arr[i]);
    }
}