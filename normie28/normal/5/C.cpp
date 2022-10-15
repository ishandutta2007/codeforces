// Credit to robs77 for this template
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
#define mod 1000000007
#define inf 100000000
/*********VARIABLE****************/
using namespace std;
typedef pair<int,int> ii;
/******************************/
char s[1000005];
stack<pair<char,int>> st; 
/*********FUNCTIONS**************/

/***********MAIN**************/

signed main(){ 
	scanf("%s",s);
	int mx = 0;
	int cnt = 1;
	for(int i = 0; s[i]; i++){
		if(!st.empty()&&st.top().first=='('&&s[i]==')'){
			st.pop();
			int idx = (st.empty()?-1:st.top().second);
			int dst = i-idx;
			if(dst!=0&&dst==mx){
				cnt++;
			}
			if(dst>mx){
				mx=dst;
				cnt=1;
				//printf("%d %d %d\n",i,idx,dst);
			}
		}
		else{
			st.push({s[i],i});
		}
	}
	printf("%d %d\n",mx,cnt);
	return 0;
}