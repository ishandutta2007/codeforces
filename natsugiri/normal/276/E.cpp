#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
#include<queue>
using namespace std;


typedef long long LL;
typedef vector<vector<int>  > Mat;
int N, Q;
Mat M;
template<class T>
struct Fenwick {
    int n;
    vector<T>data;
    Fenwick() {};
    Fenwick(int n) : n(n) {
	data=vector<T>(n);
    }
    void add(int p, T v) {
        for (; p<n; p|=p+1) data[p]+=v;
    }
    T sum(int l, int r) {
        if (l==0) {
            T t=0;
            for (; r; r&=r-1) t+=data[r-1];
            return t;
        } else {
            return sum(0, r)-sum(0, l);
        }
    }
};

int main() {
    scanf("%d%d", &N, &Q);
    M=Mat(N);
    for (int i=1; i<N; i++) {
	int a, b;
	scanf("%d%d", &a, &b); a--; b--;
	M[a].push_back(b); M[b].push_back(a);
    }

    vector<int>depth(N,-1), group(N, -1), sz(M[0].size()), depth_count;
    queue<int>qu; qu.push(0);
    depth[0]=0;
    for (int k=1; !qu.empty(); k++) {
	int e=qu.front(); qu.pop();
	if (int(depth_count.size())<=depth[e]) depth_count.push_back(1);
	else depth_count[depth[e]]++;
	
	for (int i=0; i<int(M[e].size()); i++) {
	    int f=M[e][i];
	    if (depth[f]<0) {
		depth[f]=depth[e]+1;
		qu.push(f);
	    }
	}
    }
    for (int i=0; i<int(M[0].size()); i++) {
	for (int e=M[0][i]; ;) {
	    sz[i]++;
	    group[e]=i;
	    if (M[e].size()==1) break;
	    e=(depth[M[e][0]]>depth[e]?M[e][0]:M[e][1]);
	}
    }

    Fenwick<int> all(depth_count.size());
    vector<Fenwick<int> >p(M[0].size());
    for (int i=0; i<int(M[0].size()); i++) {
	p[i]=Fenwick<int>(sz[i]);
    }

    for (;Q--;) {
	int t; scanf("%d", &t);
	if (t) {
	    int v;
	    scanf("%d", &v); v--;
	    printf("%d\n", all.sum(0, depth[v]+1) + p[group[v]].sum(0, depth[v]));
	} else {
	    int v, x, d;
	    scanf("%d%d%d", &v, &x, &d); v--;
	    if (v==0) {
		all.add(0, x); all.add(d+1, -x);		
	    } else {
		if (d>=depth[v]) {
		    int dd=d-depth[v];
		    all.add(0, x); all.add(dd+1, -x);
		    p[group[v]].add(dd, x);
		    p[group[v]].add(depth[v]+d, -x);
		} else {
		    p[group[v]].add(depth[v]-d-1, x);
		    p[group[v]].add(depth[v]+d, -x);
		}
	    }
	}
    }

    return 0;
}