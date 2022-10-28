#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
int n;
int arr[N];
map < int , int > m;
int q;
int val;
int main(){
    scanf("%d" , &n);
    for(int i = 1 ; i <= n ; ++i){
        scanf("%d" , arr + i);
        arr[i] += arr[i - 1];
        m[arr[i]] = i;
    }
    scanf("%d" , &q);
    while(q--){
        scanf("%d" , &val);
        auto it = m.lower_bound(val);
        printf("%d\n" , it -> second);
    }
}