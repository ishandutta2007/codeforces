#include <algorithm>
#include <iostream>
#include <cstring>
#include <climits>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>

#define Re register
#define LL long long
#define CLR(a,b) memset(a,b,sizeof(a))
#define FOR(i,a,b) for(Re int i = a;i <= b;++i)
#define ROF(i,a,b) for(Re int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl
#define int LL 
int N;
const int MAXN = 500000+5;
int a[MAXN];
LL sum;
int max,maxcnt,cmax;
std::vector<int> ans;

signed main(){
	scanf("%I64d",&N);
	max = cmax = INT_MIN;
	maxcnt = 0;
	FOR(i,1,N){
		scanf("%I64d",a+i);
		sum += a[i];
		if(a[i] > max){
			max = a[i];
		}
	}
	FOR(i,1,N){
		if(a[i] == max) continue;
		cmax = std::max(a[i],cmax);
	}
	//DEBUG(cmax);
	FOR(i,1,N) if(a[i] == max) maxcnt++;
	FOR(i,1,N){
		if(maxcnt > 1){
			if(sum-a[i]-max == max) ans.push_back(i);
		}
		else{
			//DEBUG(sum);DEBUG(a[i]);
			if(a[i] == max){
				if(sum-a[i]-cmax == cmax) ans.push_back(i);
			}
			else{
				if(sum-a[i]-max == max) ans.push_back(i);
			}
		}
	}
	printf("%I64d\n",(int)ans.size());
	FOR(i,0,(int)ans.size()-1) printf("%I64d ",ans[i]);
    return 0;
}