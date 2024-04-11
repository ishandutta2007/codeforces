#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
int m[N];
int c[N];
int n;
int x1 , x2;
vector < pair < long long , long long > > v;
int main(){
    scanf("%d" , &n);
    scanf("%d %d" , &x1 , &x2);
    for(int i = 1 ; i <= n ; ++i){
        scanf("%d %d" , m + i , c + i);
    }
    for(int i = 1 ; i <= n ; ++i){
        v.emplace_back(make_pair(1LL * m[i] * x1 + c[i] , 1LL * m[i] * x2 + c[i]));
    }
    sort(v.begin() , v.end());
    long long best = -1e15;
    for(auto it : v){
        if(best > it.second){
            printf("YES");
            return 0;
        }
        best = max(best , it.second);
    }
    printf("NO");
}