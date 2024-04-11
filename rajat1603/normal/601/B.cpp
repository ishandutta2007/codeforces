#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
int n , q;
int inp[N];
int arr[N];
int lft[N];
int rgt[N];
int ql , qr;
long long ans;
stack < int > s;
stack < int > r;
int main(){
    scanf("%d %d" , &n , &q);
    for(int i = 1 ; i <= n ; ++i){
        scanf("%d" , &inp[i]);
    }
    --n;
    for(int i = 1 ; i <= n ; ++i){
        arr[i] = abs(inp[i + 1] - inp[i]);
    }
    arr[0] = 1e9;
    s.push(0);
    for(int i = 1 ; i <= n ; ++i){
        while(arr[s.top()] <= arr[i]){
            s.pop();
        }
        lft[i] = s.top() + 1;
        s.push(i);
    }
    arr[n + 1] = 1e9;
    r.push(n + 1);
    for(int i = n ; i >= 1 ; --i){
        while(arr[r.top()] < arr[i]){
            r.pop();
        }
        rgt[i] = r.top() - 1;
        r.push(i);
    }
    while(q--){
        scanf("%d %d" , &ql , &qr);
        ans = 0;
        --qr;
        for(int i = ql ; i <= qr ; ++i){
            ans += 1LL * (i - max(ql , lft[i]) + 1) * (min(qr , rgt[i]) - i + 1) * arr[i];
        }
        printf("%lld\n" , ans);
    }
}