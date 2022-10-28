#include "bits/stdc++.h"
using namespace std;
const int N = 1e6 + 6;
const int SQN = 1e3 + 3;
vector < int > v[SQN];
int n;
int x[N];
int y[N];
int main(){
    scanf("%d" , &n);
    for(int i = 1 ; i <= n ; ++i){
        scanf("%d %d" , x + i , y + i);
        v[x[i] / SQN].emplace_back(i);
    }
    for(int i = 0 ; i < SQN ; i += 2){
        sort(v[i].begin() , v[i].end() , [](int a , int b){
            return y[a] < y[b];
        });
    }
    for(int i = 1 ; i < SQN ; i += 2){
        sort(v[i].begin() , v[i].end() , [](int a , int b){
            return y[a] > y[b];
        });
    }
    for(int i = 0 ; i < SQN ; ++i){
        for(int x : v[i]){
            printf("%d " , x);
        }
    }
}