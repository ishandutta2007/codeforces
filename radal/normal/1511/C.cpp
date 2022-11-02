#include <bits/stdc++.h>
#pragma GCC target ("avx,avx2,fma")
#pragma GCC optimization ("O2")
#pragma GCC optimization ("unroll-loops")
#define X first
#define Y second
#define debug(x) cerr << #x << ": " << x << endl;
#define endl '\n'
#define pb push_back
#define rep(i,l,r) for (int i=l; i<r; i++)
#define repr(i,r,l) for (int i=r; i>=l; i--)
using namespace std;
typedef long long ll;
typedef pair<int,int> pll;
const long long int N=3e5+10,mod = 1e9+7,inf=1e18,dlt = 12251;
ll poww(int a,int k){
    if (!k) return 1;
    if (k == 1) return a;
    ll r = poww(a,k/2);
    return (((r*r)%mod)*poww(a,k%2))%mod;
}
int a[N],ind[N],ca[N],p[N];
int main(){
    memset(ind,63,sizeof ind);
    int n,q;
    cin >> n >> q;
    list <int> li;
    rep(i,1,n+1){
        cin >> a[i];
        if (ind[a[i]] > 1e7){
            li.pb(a[i]);
            p[a[i]] = li.size();
            ind[a[i]] = i;
        }
    }
    rep(i,1,q+1){
        int x;
        cin >> x;
        int j = 0;
        for (auto it = li.begin(); it != li.end(); it++){
            j++;
            if (*it == x){
                li.erase(it);
                li.push_front(x);
                break;
            }
        }
        if (!ca[x]){
            cout << ind[x]+j-p[x] << ' ';
            ca[x] = i;
            continue;
        }
        cout << j << ' ';
    }
    return 0;
}