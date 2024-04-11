#define _CRT_SECURE_NO_WARNINGS
#define fast ios::sync_with_stdio(false); cin.tie(0)
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define pb push_back

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <unordered_set>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;
typedef pair<ld, ld> pld;

const int rsz = 1e6 + 5, sz = 1e5+5;
int n, v[sz];
ll a, b;

int main() {
    //fast;
    unordered_set<int> mem;
    scanf("%d",&n);
    int tmp;
    foru(i, 0, n){
        scanf("%d",&v[i]);
    }
    scanf("%lld %lld",&a,&b);
    sort(v, v + n);
    n = unique(v, v + n) - v;
    int cur = a, ret = 0;
    while(cur>b){
        int bst = cur-1;
        for (int i = 0; i < n; i++){
            int dst = cur - cur % v[i];
            if(dst>=b)bst=min(dst,bst);
            else{
                v[i]=v[n-1];
                i--;
                n--;
            }
        }
        cur=bst;
        ret++;
    }
    printf("%d\n",ret);
    return 0;
}