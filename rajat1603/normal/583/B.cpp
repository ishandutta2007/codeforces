#include "bits/stdc++.h"
using namespace std;
const int N = 1001;
int n;
int arr[N];
int done[N];
int cnt;
int main(){
    cin >> n;
    for(int i = 1 ; i <= n ; ++i){
        cin >> arr[i];
    }
    int cur = 1;
    int ans = 0;
    while(cnt != n){
        if(cur == 1){
            while(cur <= n){
                if(arr[cur] <= cnt && !done[cur]){
                    ++cnt;
                    done[cur] = 1;
                }
                ++cur;
            }
            cur = n;
        }
        else{
            cur = n;
            while(cur >= 1){
                if(arr[cur] <= cnt && !done[cur]){
                    ++cnt;
                    done[cur] = 1;
                }
                --cur;
            }
            cur = 1;
        }
        ++ans;
    }
    cout << ans - 1;
}