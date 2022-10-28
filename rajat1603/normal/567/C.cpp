#include "bits/stdc++.h"
using namespace std;
const int N = 2e5 + 5;
int n , k;
int arr[N];
map < long long , long long > m;
map < long long , long long > cnt;
long long ans = 0;
int main(){
    scanf("%d %d" , &n , &k);
    for(int i = 1 ; i <= n ; ++i){
        scanf("%d" , &arr[i]);
    }
    for(int i = n ; i >= 1 ; --i){
        ans += m[1LL * arr[i] * k];
        m[arr[i]] += cnt[1LL * arr[i] * k];
        cnt[arr[i]]++;
    }
    cout << ans;
}