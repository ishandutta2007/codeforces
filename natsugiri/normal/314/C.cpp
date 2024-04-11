#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
#include<set>
using namespace std;

typedef long long LL;
const LL MOD=1000000007;

struct SegTree {
    int n, m;
    vector<LL>all, part;
    SegTree(int n) :n(n) {
	m=1;
	for (;m<n;) m*=2;
	all=part=vector<LL>(m*2);
    }
    void add(int x, int y, LL v) { add(x, y, 1, 0, m, v); }
    void add(int x, int y, int k, int l, int r, LL v) {
	if (x<=l && r<=y) {
	    all[k]=(all[k]+v)%MOD;
	    return;
	} else if (x<r && l<y) {
	    part[k] = (part[k]+(min(y, r)-max(x, l))*v)%MOD;
	    add(x, y, k*2, l, (l+r)/2, v);
	    add(x, y, k*2+1, (l+r)/2, r, v);
	}
    }
    LL sum(int x, int y) { return sum(x, y, 1, 0, m); }
    LL sum(int x, int y, int k, int l, int r) {
	if (r<=x || y<=l) return 0;
	if (x<=l && r<=y) return ((r-l)*all[k]+part[k])%MOD;
	return ((min(y, r)-max(x, l))*all[k]
		+ sum(x, y, k*2, l, (l+r)/2)
		+ sum(x, y, k*2+1, (l+r)/2, r))%MOD;
    }
};


int N, A[100010];
int main() {
    scanf("%d", &N);
    SegTree tree(1000100);
    for (int i=0; i<N; i++) {
	scanf("%d", A+i);
	LL x = tree.sum(0, A[i]+1), y = tree.sum(A[i], A[i]+1);
	tree.add(A[i], A[i]+1, ((x+1)*A[i]%MOD-y)%MOD);
	
	//cout<<tree.sum(0, 1000099)<<endl;
    }
    LL x = tree.sum(0, 1000099);
    cout<<(x%MOD+MOD)%MOD<<endl;
    
    return 0;
}