#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;


typedef long long LL;
struct SegTree {
    int n, m;
    vector<int>data;
    vector<int>flag;
    SegTree(){}
    SegTree(int n) : n(n) {
        m=1;
        for (;m<n;) m<<=1;
        //data = new int[m*2];
	data=vector<int>(m*2, 0);
	flag=vector<int>(m*2, 0);
    }

    int query(int x, int y) { return query(x, y, 1, 0, m); }
    int query(int x, int y, int k, int l, int r) {
	int t=0;
        if (r<=x || y<=l) return 0;
        else if (x<=l && r<=y) {
	    t=data[k];
	    return flag[k]?r-l-t:t;
	} else {
	    t=query(x, y, k*2, l, (l+r)/2)+query(x, y, k*2+1, (l+r)/2, r);
	    return flag[k]?min(r,y)-max(l,x)-t:t;
	}
    }
    int XOR(int x, int y) { return XOR(x, y, 1, 0, m); }
    int XOR(int x, int y, int k, int l, int r) {
        if (r<=x || y<=l) ;//return data[k];
        else if (x<=l && r<=y) {
	    flag[k]=1-flag[k];
	} else {
	    int t=XOR(x, y, k*2, l, (l+r)/2)+ XOR(x, y, k*2+1, (l+r)/2, r);
	    data[k]=t;
	}
	return flag[k]?r-l-data[k]:data[k];
    }

    int at(int p) { return data[p+m]; }
};

int N, M, A[100010];
SegTree st[20];
int main() {
    scanf("%d", &N);
    for (int i=0; i<N; i++) scanf("%d", A+i);
    for (int i=0; i<20; i++) st[i]=SegTree(N);
    for (int i=0; i<N; i++) {
	for (int j=0; j<20; j++) {
	    if ((1<<j)&A[i]) {
		st[j].XOR(i, i+1);
	    }
	}
    }
    
    scanf("%d", &M);
    for (int i=0; i<M; i++) {
	int t,l,r;
	scanf("%d%d%d", &t, &l, &r);
	l--; r--;
	if (t==1) {
	    LL s=0;
	    for (int j=0; j<20; j++) {
		s+=(1LL<<j)*st[j].query(l, r+1);
	    }
	    cout<<s<<endl;
	} else {
	    int n;
	    scanf("%d", &n);
	    for (int j=0; j<20; j++) {
		if ((1<<j)&n) {
		    st[j].XOR(l, r+1);
		}
	    }
	}
    }
    return 0;
}