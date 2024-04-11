#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
#define PB push_back
#define fi first
#define se second
#define MP make_pair
const int P = 1000000007;

const int V=2100;
const int En=200000;
const int ooo=1e9;
const LL oo = (LL) ooo * ooo;
struct Edge{int num,ne;LL c;}e[En];
int d[V],p[V],pre[V];LL low[V];
int gap[V],cur[V];
int N,K,st,ed;
void add(int x,int y,LL c)
{
    //printf("Add %d %d %lld\n", x, y, c);
	e[K].num=y;e[K].c=c;
	e[K].ne=p[x];p[x]=K++;
	e[K].num=x;e[K].c=0;
	e[K].ne=p[y];p[y]=K++;
}
LL sap()
{
	LL ret=0;
	bool fail;
	for(int i=0;i<=N;i++)
	{
		low[i]=gap[i]=d[i]=0;
		cur[i]=p[i];
	}
	low[st]=oo;gap[0]=N;int u=st;
	while(d[st]<N)
	{
		fail=true;
		for(int i=cur[u];i!=-1;i=e[i].ne)
		{
			int v=e[i].num;cur[u]=i;
			if(e[i].c&&d[u]==d[v]+1)
			{
				pre[v]=i;
				low[v]=min(low[u],e[i].c);u=v;
				if(u==ed)
				{
					do
					{
						e[pre[u]].c-=low[ed];
						e[pre[u]^1].c+=low[ed];
						u=e[pre[u]^1].num;
					}while(u!=st);
					ret+=low[ed];
				}
				fail=false;break;
			}
		}
		if(fail)
		{
			gap[d[u]]--;
			if(!gap[d[u]])return ret;
			d[u]=N;
			for(int i=p[u];i!=-1;i=e[i].ne)
			if(e[i].c)d[u]=min(d[u],d[e[i].num]+1);
			gap[d[u]]++;cur[u]=p[u];
			if(u!=st)u=e[pre[u]^1].num;
		}
	}
	return ret;
}

int n, x[V], y[V], z[V];

int main() {
    while (~scanf("%d", &n)) {
        map<PII, int> mp;
        LL s = 0;
        for (int i = 0; i < n; ++i) {
            scanf("%d%d%d",&x[i], &y[i], &z[i]);
            mp[{x[i], y[i]}] = i;
            s += z[i];
        }
        N = 2 * n + 2;
        st = N - 2;
        ed = N - 1;
        for (int i = 0; i < N; ++i) p[i] = -1; K = 0;
        for (int i = 0; i < n; ++i) {
            add(2 * i, 2 * i + 1, z[i]);
            if (x[i] % 2 != 0) {
                if (y[i] % 2 == 0) {
                    add(st, 2 * i, oo);
                    for (int dx = -1; dx <= 1; dx += 2) {
                        for (int dy = 0; dy <= 0; dy += 2) {
                            if (mp.find({x[i] + dx, y[i] + dy}) != mp.end()) {
                                add(2 * i + 1, mp[{x[i] + dx, y[i] + dy}] * 2, oo);
                            }
                        }
                    }
                } else {
                    add(2 * i + 1, ed, oo);
                }
            } else {
                if (y[i] % 2 == 0) {
                    for (int dx = 0; dx <= 0; dx += 2) {
                        for (int dy = -1; dy <= 1; dy += 2) {
                            if (mp.find({x[i] + dx, y[i] + dy}) != mp.end()) {
                                add(2 * i + 1, mp[{x[i] + dx, y[i] + dy}] * 2, oo);
                            }
                        }
                    }
                } else {
                    for (int dx = -1; dx <= 1; dx += 2) {
                        for (int dy = 0; dy <= 0; dy += 2) {
                            if (mp.find({x[i] + dx, y[i] + dy}) != mp.end()) {
                                add(2 * i + 1, mp[{x[i] + dx, y[i] + dy}] * 2, oo);
                            }
                        }
                    }
                }
            }
        }
        printf("%I64d\n", s - sap());
    }
    return 0;
}

/*
5
0 0 4
0 1 5
1 0 3
1 1 1
-1 1 2

32
2 2 1
2 3 1
3 2 1
3 3 1
2 6 1
2 5 1
3 6 1
3 5 1
2 8 1
2 9 1
1 8 1
1 9 1
2 12 1
2 11 1
1 12 1
1 11 1
6 2 1
7 2 1
6 3 1
5 3 1
6 6 1
7 6 1
5 5 1
6 5 1
6 8 1
5 8 1
6 9 1
7 9 1
6 12 1
5 12 1
6 11 1
7 11 1
*/