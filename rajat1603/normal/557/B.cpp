#include "bits/stdc++.h"
using namespace std;
const int N = 2e5 + 5;
const double eps = 1e-7;
int n , w;
int arr[N];
double x;
int main(){
    cin >> n >> w;
    for(int i = 1 ; i <= n + n ; ++i){
        cin >> arr[i];
    }
    sort(arr + 1 , arr + 1 + n + n);
    if(arr[1] * 2 > arr[n + 1]){
        x = arr[n + 1];
        x /= 2.0;
    }
    else{
        x = arr[1];
    }
    x *= 3.0 * n;
    if(x > w){
        x = w;
    }
    printf("%.6lf" , x);
}