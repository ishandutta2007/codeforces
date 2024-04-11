// Credit to robs77 for this template
/***********HEADER***************/
#include <iostream>
#include <bitset>
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

#define ll  int64_t 
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
using namespace std;
typedef pair<int,int> ii;
/******************************/
const int maxn = 100000+10;
ll a[3],n,i,j,x,y,minn=0;
char c[200001];
vector <ll> all;
/*********FUNCTIONS**************/
 
 
/***********MAIN**************/
 
signed main(){
	int n;
	scanf("%d", &n);
 
	vector <int> v(n);
 
	for(int i = 0; i < n; i++) {
		scanf("%d", &v[i]);
	}
 
	if(n == 1) {
		printf("1\n");
		return 0;
	}
 
	vector <int> cres(n,0);
	vector <int> decres(n,0);
 
	decres[0] = 1;
 
	for(int i = 1; i < n; i++) {
		if(v[i] > v[i-1]) {
			decres[i] = decres[i-1] + 1;
		} else {
			decres[i] = 1;
		}
	}
 
	cres[n-1] = 1;
 
	for(int i = n-2; i >= 0; i--) {
		if(v[i] < v[i+1]) {
			cres[i] = cres[i+1] + 1;
		} else {
			cres[i] = 1;
		}	
	}
 
	int resp = -1;
 
	// trabalha as pontas de forma diferente
	resp = max(resp, cres[1]+1);
 
	resp = max(resp, decres[n-2]+1);
 
	for(int i = 1; i < n-1; i++) {
		if(v[i-1]+1 < v[i+1]) {
			resp = max(decres[i-1] + cres[i+1] + 1, resp);
		}
 
		resp = max(resp, decres[i-1]+1);
		resp = max(resp, cres[i+1]+1);
	}
 
	printf("%d\n",resp );
 
    return 0;
}
 
//