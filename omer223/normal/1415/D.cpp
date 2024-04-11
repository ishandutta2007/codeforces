
#define fast ios::sync_with_stdio(false); cin.tie(0);
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define pb push_back

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <set>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;
typedef pair<ll, ll> pll;

const int sz = 3e5, BITS = 30;
int n, a[sz], p[sz];

int query(int i, int j){
    if(i>j)return 0;
    return p[j]^(i?p[i-1]:0);
}

void solve() {
    cin >> n;
    foru(i, 0, n) {
        cin >> a[i];
        p[i]=(i?p[i-1]:0)^a[i];
    }
    if(n>=100)cout<<1<<'\n';
    else {
        int bst = 1e9;
        foru(i,0,n){
            foru(j,i,n){
                int l = query(i,j);
                foru(k,j+1,n){
                    int r = query(j+1,k);
                    if(l>r or (i>0 and a[i-1]>l) or (k<n-1 and a[k+1]<r))bst=min(bst,(j-i)+(k-j-1));
                }
            }
        }
        cout<<(bst>n?-1:bst)<<'\n';
    }
}

int main() {
    fast;
    int t;
    //cin >> t;
    t = 1;
    while (t--)solve();
    return 0;
}