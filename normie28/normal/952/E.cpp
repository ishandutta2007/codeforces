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
string s;
/*********FUNCTIONS**************/
 void solveE() {
  int n;
  cin >> n;
  string s, s2;
  int answer = 0;
  int soft_am = 0, hard_am = 0;
  for (int i = 0; i < n; ++i) {
    cin >> s;
    cin >> s2;
    if (s2 == "soft") {
      ++soft_am;
    } else {
      ++hard_am;
    }
  }
  for (int i = 1; i < 30; ++i) {
    if (hard_am <= i * i / 2 && soft_am <= i * i - i * i / 2 || soft_am <= i * i / 2 && hard_am <= i * i - i * i / 2) {
      cout << i << endl;
      return;
    }
  }
}
 
 
/***********MAIN**************/
 
 // ya succ
 
int main()
{
	solveE();
}