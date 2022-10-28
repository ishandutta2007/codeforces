#include "bits/stdc++.h"
using namespace std;
const int N = 2005;
int n;
pair < long long , long long > arr[N] , x1 , x2;
long long ans = 1LL << 61;
long long dist2 = 0;
long long sqr(long long x){
    return x * x;
}
long long dist(pair < long long , long long > a , pair < long long , long long > b){
    return sqr(a.first - b.first) + sqr(a.second - b.second);
}
bool cmp(pair < long long , long long > a , pair < long long , long long > b){
    return dist(x1 , a) <= dist(x1 , b);
}
int main(){
    cin >> n;
    cin >> x1.first >> x1.second;
    cin >> x2.first >> x2.second;
    for(int i = 1 ; i <= n ; ++i){
        cin >> arr[i].first >> arr[i].second;
    }
    sort(arr + 1 , arr + 1 + n , cmp);
    arr[0] = x1;
    for(int i = n ; i >= 0 ; --i){
        ans = min(ans , dist(arr[i] , x1) + dist2);
        dist2 = max(dist2 , dist(arr[i] , x2));
    }
    cout << ans;
}