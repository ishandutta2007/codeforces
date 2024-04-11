#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
int n;
int m;
vector < int > a;
vector < int > b;
int l = 0 , r = 1e9;
long long ans = 1e18;
int input;
long long steps(int k){
    long long res = 0;
    for(int x : a){
        res += max(0 , k - x);
    }
    for(int x : b){
        res += max(0 , x - k);
    }
    return res;
}
int main(){
    cin >> n >> m;
    while(n--){
        cin >> input;
        a.emplace_back(input);
    }
    while(m--){
        cin >> input;
        b.emplace_back(input);
    }
    for(int i = 1 ; i <= 52 ; ++i){
        int mid1 = l + (r - l) / 3;
        int mid2 = r - (r - l) / 3;
        long long x = steps(mid1);
        long long y = steps(mid2);
        ans = min(ans , min(x , y));
        if(x < y){
            r = mid2;
        }
        else{
            l = mid1;
        }
    }
    cout << ans;
}