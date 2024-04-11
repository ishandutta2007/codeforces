#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
int n , m , w;
int arr[N];
int mark[N];
int l = 1;
int r = 1e9 + N;
bool check(int val){
    int days = 0;
    memset(mark , 0 , sizeof(int) * N);
    for(int i = 1 ; i <= n && days <= m ; ++i){
        mark[i] += mark[i - 1];
        if(arr[i] + mark[i] < val){
            days += val - (arr[i] + mark[i]);
            mark[min(i + w , n + 1)] -= val - (arr[i] + mark[i]);
            mark[i] += val - (arr[i] + mark[i]);
        }
    }
    return days <= m;
}
int main(){
    cin >> n >> m >> w;
    for(int i = 1 ; i <= n ; ++i){
        cin >> arr[i];
    }
    while(l < r){
        int mid = l + r >> 1;
        if(check(mid)){
            l = mid + 1;
        }
        else{
            r = mid;
        }
    }
    cout << l - 1;
}