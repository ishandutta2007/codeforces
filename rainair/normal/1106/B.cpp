#include <algorithm>
#include <iostream>
#include <cstring>
#include <climits>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>

#define fi first
#define lc (x<<1)
#define se second
#define U unsigned
#define rc (x<<1|1)
#define Re register
#define LL long long
#define MP std::make_pair
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(Re int i = a;i <= b;++i)
#define ROF(i,a,b) for(Re int i = a;i >= b;--i)
#define SFOR(i,a,b,c) for(Re int i = a;i <= b;i+=c)
#define SROF(i,a,b,c) for(Re int i = a;i >= b;i-=c)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

#define int LL

const int MAXN = 200000 + 50;

int N,M,head = 1;
int f[MAXN];

struct Node{
	int val,num,id;
	bool operator < (const Node &t) const{
        return val == t.val ? id < t.id : val < t.val;
	}
}a[MAXN];

signed main(){
	scanf("%I64d%I64d",&N,&M);
	FOR(i,1,N) scanf("%I64d",&a[i].num);
	FOR(i,1,N) scanf("%I64d",&a[i].val);
	FOR(i,1,N) a[i].id = i;std::sort(a+1,a+N+1);FOR(i,1,N) f[a[i].id] = i;
	while(M--){
        int x,y;
		scanf("%I64d%I64d",&x,&y);
		int ans = 0,now = f[x];
		if(a[now].num >= y){
            ans += a[now].val*y;
            a[now].num -= y;
            y = 0;
        }
		else{
            ans += a[now].num*a[now].val;
            y -= a[now].num;
            a[now].num = 0;
        }
		if(y){
			for(;head<=N;){
				if(a[head].num >= y){
                    ans += a[head].val*y;
                    a[head].num -= y;
                    y = 0;break; 
                }else{
                    ans += a[head].val*a[head].num;
                    y -= a[head].num;
                    a[head].num = 0;
                    ++head;
                }
            }
        }
		if (head>N||y) puts("0");
		else printf("%I64d\n",ans);
	}
	return 0;
}