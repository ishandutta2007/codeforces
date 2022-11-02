#pragma GCC optimize("O4", "unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx2,tune=native")

#include <bits/stdc++.h>
using namespace std;
 
typedef unsigned int ll;
using namespace std;
 
unordered_map<ll, ll> nums;
bool mydec[31];
 
void dec(ll n) {
    for (int i = 30; i >= 0; --i) {
        mydec[i] = (n & 1);
        n >>= 1;
    }
}
 
void add(ll n) {
    dec(n);
    ll ptr = 1;
    for (int i = 0; i < 31; ++i) {
        ptr = (ptr << 1) + mydec[i];
        ++nums[ptr];
    }
}
 
void grab(ll n) {
    dec(n);
    ll ptr = 1, ans = 0;
    for (int i = 0; i < 31; ++i) {
        if (nums.count((ptr << 1)  + mydec[i])) ptr = (ptr << 1) + mydec[i];
        else ptr = (ptr << 1) + !mydec[i];
        --nums[ptr];
        if (nums[ptr] == 0) nums.erase(ptr);
        ans = (ans << 1) + (ptr & 1);
    }
    cout << (ans ^ n) << ' ';
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<ll> a(n);
    ll temp;
    for (auto &i : a) cin >> i;
    for (int i = 0; i < n; ++i) cin >> temp, add(temp);
    for (auto i : a) grab(i); 
    return 0;
}