#include "bits/stdc++.h"
using namespace std;
const int N = 2e5 + 5;
int n , k , a;
int m;
int arr[N];
bool mark[N];
int l , r;
bool check(int pos){
    for(int i = 1 ; i <= n ; ++i){
        mark[i] = 1;
    }
    mark[0] = 0;
    mark[n + 1] = 0;
    for(int i = 1 ; i <= pos ; ++i){
        mark[arr[i]] = 0;
    }
    int last = 1;
    int res = 0;
    for(int i = 1 ; i <= n + 1 ; ++i){
        if(!mark[i]){
            res += (i - last + 1) / (a + 1);
            last = i + 1;
        }
    }
    return res >= k;
}
int main(){
    cin >> n >> k >> a;
    cin >> m;
    for(int i = 1 ; i <= m ; ++i){
        cin >> arr[i];  
    }
    if(check(m)){
        cout << -1;
    }
    else{
        l = 1;
        r = m;
        while(l < r){
            int mid = l + r >> 1;
            if(check(mid)){
                l = mid + 1;
            }
            else{
                r = mid;
            }
        }
        cout << l;
    }
}