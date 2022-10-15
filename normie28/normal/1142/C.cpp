
// Problem : E. Magical Permutation
// Contest : Codeforces - Codeforces Round #558 (Div. 2)
// URL : https://codeforces.com/problemset/problem/1163/E
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

/*
 A Submission by $%U%$
 at time: $%Y%$-$%M%$-$%D%$ $%h%$:$%m%$:$%s%$
*/
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define fef(i,a,b) for(ll i=a;i<=b;i++)
#define rer(i,a,b) for(ll i=b;i>=a;i--)
#define wew while(true)
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define FILE_IN "cseq.inp"
#define FILE_OUT "cseq.out"
#define ofile freopen(FILE_IN,"r",stdin);freopen(FILE_OUT,"w",stdout)
#define fio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define nfio cin.tie(0);cout.tie(0)
#define max(x,y) (((x)>(y))?(x):(y))
#define min(x,y) (((x)<(y))?(x):(y))
#define ord(a,b,c) ((a>=b)and(b>=c))
#define MOD (ll(1000000007))
#define MAX 300001
#define mag 320
#define p1 first
#define p2 second.first
#define p3 second.second
#define fi first
#define se second
#define pow2(x) (ll(1)<<x)
#define pii pair<int,int>
#define piii pair<int,pii>
#define For(i,__,___) for(int i=__;i<=___;i++)
#define Rep(i,__,___) for(int i=__;i>=___;i--)
#define ordered_set tree<long long,null_type,less<long long>,rb_tree_tag,tree_order_statistics_node_update>
#define endl "\n"
#define bi BigInt
typedef long long ll;
//---------END-------//
const int N = 5 * 100001;
 
int n;
struct point{
  ll x , y;
  bool operator<(const point &rhs)const{
    if(rhs.x != x)return x < rhs.x;
    return y > rhs.y;
  }
};
ll cross(point s , point a , point b){
  return (a.x-s.x)*(b.y-s.y)-(a.y-s.y)*(b.x-s.x);
}
point p[N];
 
int main() {
  cin >> n;
  for (int i = 0; i < n; ++i){
    scanf("%lld%lld",&p[i].x,&p[i].y);
    p[i].y -= p[i].x*p[i].x;
    //cout << p[i].x << " "<< p[i].y << endl;
  }
  sort(p,p+n);
  vector<point> up;
  for(int i = n-1; i >= 0 ; --i){
    if(i && p[i].x == p[i-1].x)continue;
    while(up.size() >= 2 && cross(up[up.size()-2],up[up.size()-1],p[i]) <= 0)up.pop_back();
    up.push_back(p[i]);
  }
/*  for (int i = 0; i < up.size(); ++i){
    cout << "TOOK " << up[i].x << " " << up[i].y << endl;
  }*/
  cout << up.size()-1 << endl;
  
  return 0;
}