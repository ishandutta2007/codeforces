#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>
#include <algorithm>
#include <queue>
#include <memory.h>
#include <stack>
#define mp make_pair
#define pb push_back                     
#define setval(a,v) memset(a,v,sizeof(a))

#if ( _WIN32 || __WIN32__ )
    #define LLD "%I64d"
#else
    #define LLD "%lld"
#endif

using namespace std;

typedef long long ll;
typedef long double ld;

const int MAXN = 110000;

int n,t;

int b[MAXN];
pair<int,int> _b[MAXN];

int ans[MAXN];
int ptr[MAXN];


void solve(){
	for (int i = 0; i < n; i++){
		scanf("%d",&_b[i].first);
		_b[i].second = i;
	}
	sort(_b,_b+n);
	int maxc = 0;
	for (int i = 0; i < n; i++){
		if (i && _b[i].first != _b[i-1].first) maxc++;
		b[_b[i].second] = maxc;
	}
	maxc++;

	memset(ans,0x3f,sizeof(ans));
	memset(ptr,0,sizeof(ptr));

	int tmp;
	for (int i = 0; i < t && i < maxc; i++){
		for (int j = 0; j < n; j++){
			tmp = b[j];
			while (ans[ptr[tmp]] < tmp)
				ptr[tmp]++;
			ans[ptr[tmp]] = tmp;
		}
	}

	cout << *max_element(ptr,ptr+maxc) + 1 << endl;
}


int main(){
  #ifdef LOCAL
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif

  int tests;
  scanf("%d %d %*d %d",&tests,&n,&t);

  for (int i = 0; i < tests; i++)
  	solve();
  	      
  return 0;
}