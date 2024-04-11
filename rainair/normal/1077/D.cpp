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
const int MAXN = 300000+5;
int N,K;
int a[MAXN];

struct Num{
	int num,cnt;
	bool operator < (const Num &other) const{
		return cnt > other.cnt;
	}
}p[MAXN];

std::vector<int> ans,tt;
int last,max;

inline bool check(int k){
	int cnt = 0;tt.clear();
	FOR(i,1,last){
		int t = p[i].cnt;
		if(t < k) continue;
		int maxer = 0;
		FOR(div,1,t){
			if(t/div >= k){
				maxer = div;
				if(cnt + maxer >= K){
					FOR(j,1,maxer) tt.push_back(p[i].num);
					return true;
				}
			}
			else break;
		}
		FOR(k,1,maxer) tt.push_back(p[i].num);
		cnt += maxer;
		if(cnt >= K) return true;
	}
	return cnt >= K;
}

int main(){
	scanf("%d%d",&N,&K);
	FOR(i,1,N){
		scanf("%d",a+i);
		p[a[i]].cnt++;
		p[a[i]].num = a[i];
		max = std::max(max,a[i]);
	}
	std::sort(p+1,p+max+1);
	while(p[last+1].cnt) last++;
	int L = 1,R = N;
	while(L <= R){
		//DEBUG(L);DEBUG(R);
		int mid = (L + R) >> 1;
		if(check(mid)) L = mid+1,ans = tt;
		else R = mid-1;
		//FOR(i,0,(int)tt.size()-1) printf("%d ",tt[i]);puts("");
	}
	FOR(i,0,K-1) printf("%d ",ans[i]);
    return 0;
}