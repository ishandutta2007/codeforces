#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 1;
const int M = 1e5 + 1;
const int A = 1e9 + 1;
const int B = 1e4 + 1;
const int P = 1e9 + 1;
int n , m , a;
int b[N];
int p[N];
int R , S;
int main(){
    cin >> n >> m >> a;
    for(int i = 1 ; i <= n ; ++i){
        cin >> b[i];
    }
    for(int i = 1 ; i <= m ; ++i){
        cin >> p[i];
    }
    sort(p + 1 , p + 1 + m);
    sort(b + 1 , b + 1 + n);
    if(a + b[n] < p[1]){
        cout << "0 0";
        return 0;
    }
    int l = 1;
    int r = min(n , m);
    while(l <= r){
        int mid = (l + r) >> 1;
        int extrafund = 0;
        long long fundleft = a;
        for(int i = 1 , j = n - mid + 1 ; i <= mid && j <= n ; ++i , ++j){
            extrafund += min(p[i] , b[j]);
            fundleft -= max(0 , p[i] - b[j]);
        }
        if(fundleft >= 0){
            for(int i = 1 , j = n - mid + 1 ; i <= mid && j <= n && fundleft > 0 ; ++i , ++j){
                extrafund -= min(fundleft ,1LL *  min(p[i] , b[j]));
                fundleft -= min(p[i] , b[j]);
            }
            S = extrafund;
            R = mid;
            l = mid + 1;
        }
        else{
            r = mid - 1;
        }
    }
    cout << R << " " << S;
}