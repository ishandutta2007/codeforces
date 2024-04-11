#include "bits/stdc++.h"
using namespace std;
const int N = 305;
inline int gcd(int a , int b){
    while(b){
        int temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}
int n;
int arr[N];
int cost[N];
map < int , int > m[N];
int _g = 0;
int solve(int pos , int g){
    if(g == 1){
        return 0;
    }
    if(!pos){
        return 1 << 25;
    }
    if(m[pos].find(g) != m[pos].end()){
        return m[pos][g];
    }
    return m[pos][g] = min(solve(pos - 1  , g) , solve(pos - 1 , gcd(g , arr[pos])) + cost[pos]);
}
int main(){
    cin >> n;
    for(int i = 1 ; i <= n ; ++i){
        cin >> arr[i];
        _g = gcd(_g , arr[i]);
    }
    for(int i = 1 ; i <= n ; ++i){
        cin >> cost[i];
    }
    if(_g > 1){
        cout << "-1";
    }
    else{
        cout << solve(n , 0);
    }
}