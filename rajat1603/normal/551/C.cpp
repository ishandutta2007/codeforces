#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
int arr[N];
int cpy[N];
int n , m;
int main(){
    cin >> n >> m;
    for(int i = 1 ; i <= n ; ++i){
        cin >> arr[i];
    }
    long long l = 0 , r = 1e15;
    while(l < r){
        long long mid = l + r >> 1;
        for(int i = 1 ; i <= n ; ++i){
            cpy[i] = arr[i];
        }
        int pos = n;
        for(int i = 1 ; i <= m ; ++i){
            for(; pos && !cpy[pos] ; --pos);
            long long timer = max(0LL , mid - pos);
            while(pos && timer){
                if(timer >= cpy[pos]){
                    timer -= cpy[pos];
                    cpy[pos--] = 0;
                }
                else{
                    cpy[pos] -= timer;
                    timer = 0;
                }
            }
        }
        for(; pos && !cpy[pos] ; --pos);
        if(!pos){
            r = mid;
        }
        else{
            l = mid + 1;
        }
    }
    cout << l;
}