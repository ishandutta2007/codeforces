#include "bits/stdc++.h"
using namespace std;
const int N = 305;
int x , y;
int x2 , y2;
int n;
int a[N];
int b[N];
int c[N];
int ans = 0;
double gety(int x , int idx){
    return (1.0 * a[idx] * x + c[idx]) / (-1.0 * b[idx]);
}
int main(){
    cin >> x >> y;
    cin >> x2 >> y2;
    if(y > y2){
        swap(x , x2);
        swap(y , y2);
    }
    cin >> n;
    for(int i = 1 ; i <= n ; ++i){
        cin >> a[i] >> b[i] >> c[i];
    }
    for(int i = 1 ; i <= n ; ++i){
        if((gety(x , i) >= y && gety(x2 , i) <= y2) || (gety(x , i) <= y && gety(x2 , i) >= y2)){
            ++ans;
        }
    }
    cout << ans;
}