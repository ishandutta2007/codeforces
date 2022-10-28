#include "bits/stdc++.h"
using namespace std;
const int N = 2e3 + 3;
int n;
int arr[N];
int dp[N];
map < int , int > m;
int ans = 2;
int main(){
    cin >> n;
    for(int i = 1 ; i <= n ; ++i){
        cin >> arr[i];
        ++m[arr[i]];
    }
    ans = max(ans , m[0]);
    arr[0] = INT_MIN;
    sort(arr + 1 , arr + 1 + n);
    for(int i = 1 ; i <= n ; ++i){
        if(arr[i] == arr[i - 1]){
            continue;
        }
        for(int j = 1 ; j < i; ++j){
            int a = arr[i];
            int b = arr[j];
            if(!a && !b){
                continue;
            }
            int cur = 2;
            map < int , int > m1;
            ++m1[a];
            ++m1[b];
            while(1){
                int c = a + b;
                if(m1[c] < m[c]){
                    ++cur;
                    a = b;
                    b = c;
                    ++m1[c];
                }
                else{
                    break;
                }
            }
            ans = max(ans , cur);
        }
        for(int j = i + 1 ; j <= n ; ++j){
            int a = arr[i];
            int b = arr[j];
            if(!a && !b){
                continue;
            }
            int cur = 2;
            map < int , int > m1;
            ++m1[a];
            ++m1[b];
            while(1){
                int c = a + b;
                if(m1[c] < m[c]){
                    ++cur;
                    a = b;
                    b = c;
                    ++m1[c];
                }
                else{
                    break;
                }
            }
            ans = max(ans , cur);
        }
    }
    cout << ans;
}