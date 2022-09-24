#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

typedef long long LL;

const LL MOD=1e9;

int N, M;
LL A[200010];

int main() {
    scanf("%d%d", &N, &M);
    for (int i=0; i<N; i++) cin>>A[i];
    for (;M--;) {
	int t;
	scanf("%d", &t);
	if (t==1) {
	    int x, v;
	    scanf("%d%d", &x, &v); x--;
	    A[x]=v;
	} else if (t==2) {
	    int l, r;
	    scanf("%d%d", &l, &r); l--;
	    LL f=1, p=0, ans=0;
	    for (int i=0; i<r-l; i++) {
		ans = (ans + f * A[i+l]) % MOD;
		f=(f+p)%MOD; p=(f-p)%MOD;
	    }
	    cout<<(ans+MOD)%MOD<<endl;
	} else {
	    int l, r, d;
	    scanf("%d%d%d", &l, &r, &d); l--;
	    for (int i=0; i<r-l; i++) A[i+l]+=d;
	}
    }
    return 0;
}