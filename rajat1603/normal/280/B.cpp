#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
int n;
int arr[N];
int ans;
void solve(){
    stack < int > s;
    for(int i = 1 ; i <= n ; ++i){
        while(!s.empty() && s.top() < arr[i]){
            s.pop();
        }
        if(!s.empty()){
            ans = max(ans , arr[i] ^ s.top());
        }
        s.push(arr[i]);
    }
}
int main(){
    scanf("%d" , &n);
    for(int i = 1 ; i <= n ; ++i){
        scanf("%d" , arr + i);
    }
    solve();
    reverse(arr + 1 , arr + 1 + n);
    solve();
    printf("%d\n" , ans);
}