// Credit to robs77 for this template
/***********HEADER***************/
#include <bits/stdc++.h>
using namespace std;
/***********MACROS***************/
//#define int long long 
#define ll int64_t 
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
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define fi first 
#define se second 
 
/*********VARIABLE****************/
struct bd {ll v; ll c;};
typedef pair<int,int> ii;
/******************************/
const ll po[94]={0, 1, 1, 1, 2, 1, 2, 1, 5, 2, 2, 1, 5, 1, 2, 1, 14, 1, 5, 1, 5, 2, 2, 1, 15, 2, 2, 5, 4, 1, 4, 1, 51, 1, 2, 1, 14, 1, 2, 2, 14, 1, 6, 1, 4, 2, 2, 1, 52, 2, 5, 1, 5, 1, 15, 2, 13, 2, 2, 1, 13, 1, 2, 4, 267, 1, 4, 1, 5, 1, 4, 1, 50, 1, 2, 3, 4, 1, 6, 1, 52, 15, 2, 1, 15, 1, 2, 1, 12, 1, 10, 1, 4, 2};
ll n,i,j,x,y,z,minn=0,t,pr,a,b,k;
bd all[300001]; bd h;
ll dp[300001][3];
const int maxn = 1000;
char c[maxn][maxn];
int cur = 0;

 /*********FUNCTIONS**************/
void makec(int c) {
    while (cur != c + 1) {
        ::c[x][y] = 'X';
        y += 2;
        if (y + 10 > maxn) x += 3, y = 0;
        --cur;
        if (cur < 0) cur = 255;
    }
 
    x += 2;
    y = 0;
    ::c[x][0] = ::c[x+1][0] = 'X';
    x += 3;
    --cur;
}
/***********MAIN**************/
 
 // ya succ
 
int main()
{
	   memset(c, '.', sizeof c);
    forn(i, maxn) c[i][maxn-1] = 0;
 
    string s;
    cin >> s;
    for (char c: s) {
        makec(c);
    }
 
    
    forn(i, x+1) cout << c[i] << "\n";
 
}
//kitten