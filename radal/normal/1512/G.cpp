#include <bits/stdc++.h>
#pragma GCC target ("avx,avx2,fma")
#pragma GCC optimization ("O8")
#pragma GCC optimization ("unroll-loops")
#define X first
#define Y second
#define debug(x) cerr << #x << ": " << x << endl;
#define endl '\n'
#define pb push_back
#define mp make_pair
#define rep(i,l,r) for (int i=l; i<r; i++)
#define repr(i,r,l) for (int i=r; i>=l; i--)
using namespace std;
typedef long long ll;
typedef pair<int,int> pll;
const long long int N=1e7+20,mod = 1e9+7,inf=2e18,dlt = 12250,maxm = 131072;
int a[N],m[N];
int main(){
    ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    memset(m,-1,sizeof m);
    int T;
    cin >> T;
    rep(i,1,N-2){
        for (int j = 1; j*i < N-2; j++) a[j*i]+=i;
        if (a[i] > 1e7) continue;
        if (m[a[i]] == -1) m[a[i]] = i;
    }
    while (T--){
        int c;
        cin >> c;
        cout << m[c] << endl;
    }
}