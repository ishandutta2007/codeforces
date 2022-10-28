#include "bits/stdc++.h"
using namespace std;
int n , m;
vector < int > v;
int inp;
int main(){
    scanf("%d %d" , &n , &m);
    v.resize(n);
    for(int i = 0 ; i < n ; ++i){
        scanf("%d" , &v[i]);
    }
    sort(v.begin() , v.end());
    while(m--){
        scanf("%d" , &inp);
        int it = lower_bound(v.begin() , v.end() , inp + 1) - v.begin();
        printf("%d " , it);
    }
}