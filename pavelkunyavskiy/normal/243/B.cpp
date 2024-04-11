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

int n,m,h,t;

vector<int> g[MAXN];


void solve(int i,int j){
    vector<int> f,s,b;
    
    int ptr1 = 0,ptr2 = 0;
    int sz1 = g[i].size(), sz2 = g[j].size();

    while (ptr1 < sz1 || ptr2 < sz2){
    	if (ptr1 == sz1 || (ptr2 != sz2 && (g[i][ptr1] > g[j][ptr2]))){
    	    if (g[j][ptr2] != i) s.pb(g[j][ptr2]);
    		ptr2++;
    	}
    	else if (ptr2 == sz2 || g[i][ptr1] < g[j][ptr2]){
    		if (g[i][ptr1] != j) f.pb(g[i][ptr1]);
    		ptr1++;
    	}
    	else{
    		b.pb(g[i][ptr1]);
    		ptr1++,ptr2++;
    	}
    	if ((int)f.size() + (int)b.size() >= h && (int)s.size() + (int)b.size() - max(0,h - (int)f.size()) >= t){
    		while ((int)f.size() < h){
    			assert(b.size());
    			f.push_back(b.back());
    			b.pop_back();
    		}
    		while ((int)s.size() < t){
    			assert(b.size());
    			s.push_back(b.back());
    			b.pop_back();
    		}
    		printf("YES\n");
    		printf("%d %d\n",i+1,j+1);
    		for (int i = 0; i < (int)f.size(); i++)
    			printf("%d ",f[i]+1);
    		printf("\n");
    		for (int i = 0; i < (int)s.size(); i++)
    			printf("%d ",s[i]+1);
    		printf("\n");
    		exit(0);
    	}
    	if ((int)f.size() >= h) ptr1 = sz1;
    	if ((int)s.size() >= t) ptr2 = sz2;      
    }
}


int main(){
  #ifdef LOCAL
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif

    scanf("%d %d %d %d",&n,&m,&h,&t);

    for (int i = 0; i < m; i++){
    	int a,b;
    	scanf("%d %d",&a,&b);
    	--a,--b;
    	g[a].pb(b);
    	g[b].pb(a);
    }

    for (int i = 0; i < n; i++)
    	sort(g[i].begin(),g[i].end());

    for (int i = 0; i < n; i++){
    	for (int j = 0; j < (int)g[i].size(); j++)
    		solve(i,g[i][j]);
    }

    printf("NO\n");
    return 0;
}