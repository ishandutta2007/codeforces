#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

typedef long long LL;

string A, C;
int B, D;

LL dp[128], next[128];

int main() {
    scanf("%d%d", &B, &D);
    cin>>A>>C;
    int m=C.size();
    for (int i=1; i<128; i++) {
	int k=dp[i-1];
	for (int j=0; j<int(A.size()); j++) {
	    if (A[j]==C[k%m]) {
		k++;
	    }
	    dp[i]=k;
	    next[dp[i-1]%m]=dp[i]-dp[i-1];
	}
    }

    //for (int i=0; i<20; i++) printf("%d ", next[i]);
    LL len=0;
    for (int i=0; i<B; i++) {
	len += next[len%m];
    }
    //printf("%d\n", len);
    cout<<len/(LL(m)*D)<<endl;
    //printf("%d\n", len/(m*D));

    return 0;
}