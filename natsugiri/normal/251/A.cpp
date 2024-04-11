#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;


typedef long long LL;

int N, D, X[100010];

int main() {
    scanf("%d%d", &N, &D);
    for (int i=0; i<N; i++) scanf("%d", X+i);
    LL ans=0;
    int l=0, r=2;
    for (;r<N;) {
	if (X[r]-X[l]>D) {
	    l++;
	} else {
	    if (r-l>1) {
		ans+=(LL(r)-l)*(r-l-1LL)/2;
	    }
	    r++;
	}
    }
    cout<<ans<<endl;

    return 0;
}