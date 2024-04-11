#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j; i <= k; i++) 
#define R(i, j, k) for(int i = j; i >= k; i--) 
#define db double 
#define ll long long
using namespace std;
const int N = 444;
int n, l[N], c[N];
map<int, int> mp;
int gcd(int x, int y) { return !x || !y ? (x | y) : gcd(y % x, x); }
int shai(int x) {
    int res = 1;
    for(int i = 2; i <= sqrt(x); i++) if(x % i == 0) {
            res *= i;
            while(x % i == 0) x /= i;
        }
    return res * x;
}
int main() {
    scanf("%d", &n);
    L(i, 1, n) scanf("%d", &l[i]), l[i] = shai(l[i]);
    L(i, 1, n) scanf("%d", &c[i]);
    mp[0] = 0;
    L(i, 1, n) for(auto x : mp) {
            int GCD = gcd(x.first, l[i]), val = x.second + c[i];
            if(!mp.count(GCD)) mp[GCD] = val;
            else mp[GCD] = min(mp[GCD], val);
        }
    printf("%d\n", !mp.count(1) ? -1 : mp[1]);
    return 0;
}