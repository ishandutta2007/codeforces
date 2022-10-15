 
// Problem : Multiple Games
// Contest : CodeChef - February Challenge 2021 Division 2
// URL : https://www.codechef.com/FEB21B/problems/MULGAME
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)
 
/*
	Normie's Template v2.0
*/
 
// Standard library in one include.
#include <bits/stdc++.h>
using namespace std;
 
// ordered_set library.
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set(el) tree<el,null_type,less<el>,rb_tree_tag,tree_order_statistics_node_update>
 
// AtCoder library. (Comment out these two lines if you're not submitting in AtCoder.) (Or if you want to use it in other judges, run expander.py first.)
//#include <atcoder/all>
//using namespace atcoder;
 
//Pragmas (Comment out these three lines if you're submitting in szkopul.)
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
 
//File I/O.
#define FILE_IN "cseq.inp"
#define FILE_OUT "cseq.out"
#define ofile freopen(FILE_IN,"r",stdin);freopen(FILE_OUT,"w",stdout)
 
//Fast I/O.
#define fio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define nfio cin.tie(0);cout.tie(0)
#define endl "\n"
 
//Order checking.
#define ord(a,b,c) ((a>=b)and(b>=c))
 
//min/max redefines, so i dont have to resolve annoying compile errors.
#define min(a,b) (((a)<(b))?(a):(b))
#define max(a,b) (((a)>(b))?(a):(b))
 
//Constants.
#define MOD (ll(1000000007))
#define MAX 300001
#define mag 320
 
//Pairs and 3-pairs.
#define p1 first
#define p2 second.first
#define p3 second.second
#define fi first
#define se second
#define pii(element_type) pair<element_type,element_type>
#define piii(element_type) pair<element_type,pii(element_type)>
 
//Quick power of 2.
#define pow2(x) (ll(1)<<x)
 
//Short for-loops.
#define ff(i,__,___) for(int i=__;i<=___;i++)
#define rr(i,__,___) for(int i=__;i>=___;i--)
 
//Typedefs.
#define bi BigInt
typedef long long ll;
typedef long double ld;
typedef short sh;
//---------END-------//
#define fore(i,ii,iii)for(int i=ii;i<iii;i++)
 
const int N=3010;
 
struct state {int len,link,next[2]={0,0};}; //clear next!!
state st[N*2];
ll dp[N*2];
int n,sz,last;
bool bad[15];
void sa_init(){
	last=st[0].len=0;sz=1;
	st[0].link=-1;
}
void sa_extend(bool c){
	int k=sz++,p;
	st[k].len=st[last].len+1;
	for(p=last;p!=-1&&!st[p].next[c];p=st[p].link)st[p].next[c]=k;
	if(p==-1)st[k].link=0;
	else {
		int q=st[p].next[c];
		if(st[p].len+1==st[q].len)st[k].link=q;
		else {
			int w=sz++;
			st[w].len=st[p].len+1;
			//st[w].next=st[q].next;
      fore(i,0,2)st[w].next[i]=st[q].next[i];
      st[w].link=st[q].link;
			for(;p!=-1&&st[p].next[c]==q;p=st[p].link)st[p].next[c]=w;
			st[q].link=st[k].link=w;
		}
	}
	last=k;
}
 
ll solve(ll p) {
  if(dp[p]!=-1)return dp[p];
  ll r=1;
  fore(i,1,5) {
    fore(j,0,1<<i) {
      if(i==4 && bad[j])continue;
      int pos=p;
      for(int k=i-1;k>=0;k--) {
        pos=st[pos].next[(bool)(j&(1<<k))];
        if(!pos)break;
      }
      //cout<<i<<" : "<<bitset<4>(j)<<":"<<pos<<endl;
      if(pos)r=(r+solve(pos))%MOD;
    }
  }
  return dp[p]=r;
}
 
int main() {
  bad[3]=bad[5]=bad[14]=bad[15]=1;
	sa_init();
  scanf("%d",&n);
  fore(i,0,n) {
    bool x;
    scanf("%d",&x);
    sa_extend(x);
    memset(dp,-1,sizeof(dp));
    ll dem=(solve(0)+MOD-1)%MOD;
    printf("%lld\n",dem);
  }
}