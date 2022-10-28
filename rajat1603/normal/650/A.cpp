#include "bits/stdc++.h"
using namespace std;
int n;
int x , y;
long long ans = 0;
map < int , int > x1 , y11;
map < pair < int , int > , int > xy;
int main(){
    scanf("%d" , &n);
    for(int i = 1 ; i <= n ; ++i){
        scanf("%d %d" , &x , &y);
        ans += x1[x];
        ans += y11[y];
        ans -= xy[make_pair(x , y)];
        ++x1[x];
        ++y11[y];
        ++xy[make_pair(x , y)];
    }
    cout << ans;
}