// Thanks to robs77 for this template
/***********HEADER***************/
#include <iostream>
#include <bitset>
#include <iomanip>
#include <deque>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <string>
#include <algorithm>
#include <list>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <set>
#include <queue>
#include <map>
#include <cstdlib>
/***********MACROS***************/
//#define int long long
//#define inf 100000000000000000 
#define ll  long long 
#define LL long long
#define fri(l,k) for (i=l;i<=k;i++)
#define frj(l,k) for (j=l;j>=k;j--)
#define fij(a,b,l,k) for(i=a;i<=b;i++) for(j=l;j<=k;j++)
#define all(x) x.begin(),x.end()
#define allr(x) x.rbegin(),x.rend()
#define endl "\n"
#define pb push_back
#define _1 first
#define _2 second
#define mxsz 1000000007
#define mxval 1e9 + 7
#define grt [](auto x,auto y){return x>y;}
#define pii pair<int,int>
#define fi first 
#define se second 
#define for1(i, n) for(ll i=1; i<=n; ++i)
#define for0(i, n) for(ll i=0; i<n; ++i)
#define  SZ(items) (int)items.size()
#define  CLR(a)  memset(a,0,sizeof(a))
#define  SET(a)  memset(a,-1,sizeof(a))
#ifdef DEBUG
#define debug(...) __f(#__VA_ARGS__, __VA_ARGS__)
template < typename Arg1 >
void __f(const char* name, Arg1&& arg1)
{
    cerr << name << " is " << arg1 << std::endl;
}
template < typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args)
{
    const char* comma = strchr(names + 1, ',');
    cerr.write(names, comma - names) << " is " << arg1 << " | ";
    __f(comma + 1, args...);
}
#else
#define debug(...)
#endif 
//#define mod 1000000007
/*********VARIABLE****************/
using namespace std;
typedef pair<int,int> ii;
/******************************/
int dx[] = { 0,0,1,-1,-1,-1,1,1 };
int dy[] = { 1,-1,0,0,-1,1,1,-1 };
 
template <class T> inline T biton(T n, T pos)
{
    return n | ((T)1 << pos);
}
template <class T> inline T bitoff(T n, T pos)
{
    return n & ~((T)1 << pos);
}
template <class T> inline T ison(T n, T pos)
{
    return (bool)(n & ((T)1 << pos));
}
template <class T> inline T gcd(T a, T b)
{
    while (b)
    {
        a = a%b;
        swap(a, b);
    }
    return a;
}
template <class T> inline T bigmod(T p, T e, T m)
{
    T ret = 1;
    for (; e > 0; e >>= 1)
    {
        if (e & 1)
            ret = (ret * p) % m;
        p = (p * p) % m;
    }
    return (T)ret;
};char grid[505][505];
 
int r2,c2;
 
bool found=false;
int n,m;
 
int color[505][505];
/*********FUNCTIONS**************/
void dfs(int x,int y)
{
 
    color[x][y]=1;
 
 
    for(int i=0; i<4; i++)
    {
 
        int nxt=dx[i]+x;
        int nyt=dy[i]+y;
 
        if(nxt==r2&& nyt==c2)
        {
            debug(nxt,nyt);
            debug(grid[nxt][nyt]);
 
            if(grid[nxt][nyt]=='X')
            {
                found=true;
            }
            else if(color[nxt][nyt])
            {
                found=true;
            }
            else
            {
                dfs(nxt,nyt);
            }
        }
        else
        {
            if(grid[nxt][nyt]=='.'  && color[nxt][nyt]==0)
            {
                dfs(nxt,nyt);
            }
        }
    }
}
 
 
void solve()
{
 
    cin>>n>>m;
 
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            cin>>grid[i][j];
 
        }
    }
 
 
 
    int r1,c1;
 
    cin>>r1>>c1>>r2>>c2;
 
    dfs(r1,c1);
 
    if(found){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
}
/***********MAIN**************/

signed main(){
    ios_base::sync_with_stdio(false);
    cout.setf(ios::fixed);
    cout.precision(10);
    cout.tie(nullptr);
    cin.tie(nullptr);
 
    int t = 1;
    while (t--)
    {
        solve();
    }
}