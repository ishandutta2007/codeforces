#include <bits/stdc++.h>
using namespace std;
#define int int64_t
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef vector<bool> vb;
typedef vector<vb> vvb;
#define x first
#define y second
#define pb push_back
#define loop(i,s,e) for(int i=(s);i<(e);(i)++)
#define loopr(i,s,e) for(int i=(e)-1;i>=(s);(i)--)
#define chkmax(a,b) a=max(a,b)
#define chkmin(a,b) a=min(a,b)
#define all(x) x.begin(),x.end()
const int INF = 1e9, MOD = 1e9+7;

vi vec;
void solve(int n, int k, int m=1){
    if (k-1>=(n+1)/2){
        loop(i,1,k) vec[i] = m, n--;
        vec[0] = n*m;
        return ;
    }
    int dif = n-k;
    if (dif%2==0){
        n = n-(k-2);
        vec[1] = vec[0] = n/2 * m;
        loop(i,2,k) vec[i] = m;
        return ;
    }
    if (n%2 == 1){
        vec[k-1] = m;
        k--;
        n--;
    }
    solve(n/2, k, m*2);
}
int solve(){
    int n,k; cin>>n>>k;
    vec.clear(), vec.resize(k);
    solve(n,k);
    int l = 1, s = 0;
    loop(i,0,k){
        l = l*vec[i] / __gcd(vec[i], l);
        s += vec[i];
    }
    // cout<<"SUM: "<<s<<" "<<l<<endl;
    loop(i,0,k)  cout<<vec[i]<<" ";
    cout<<endl;
    return 0;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    int t; cin>>t;
    loop(i,0,t) solve();
    return 0;
}
/*
color a
cls
g++ temp.cpp -D_GLIBCXX_DEBUG -o a & a
2
6 4
9 5


*/