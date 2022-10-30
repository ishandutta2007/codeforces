#include <bits/stdc++.h>
#pragma GCC target ("avx,avx2,fma")
#pragma GCC optimization ("O8")
#pragma GCC optimization ("unroll-loops")
#define X first
#define Y second
#define debug(x) cerr << #x << ": " << x << endl;
#define endl '\n'
#define pb push_back
#define rep(i,l,r) for (int i=l; i<r; i++)
#define repr(i,r,l) for (int i=r; i>=l; i--)
using namespace std;
typedef long long  int ll;
typedef pair<int,int> pll;
const long long int N=2e5+20,mod = 1e9+7,inf=2e8;
const long double eps = 0.0001;
bool blue[N];
vector <int> sc,adj[N];
vector<pll> adj2[N];
int n,m,k,ans[N];
pll dist[N],Q[N];
vector <int> comp[N];
vector<pair<int,pll> > edge;
int main(){
    ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    if (n == 1){
        cout << 4;
        return 0;
    }
    if (!(n%2)){
        n/=2;
        cout << (n+1)*(n+1);
        return 0;
    }
    int a = n/2,b = n/2+1;
    if (a%2) swap(a,b);
    b = b+1;
    a += 1;
    cout << a*b*2;
    return 0;
}