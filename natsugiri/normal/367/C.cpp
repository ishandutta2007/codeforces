#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

typedef long long LL;

int N, M;
int W[2000010];

int main() {

    scanf("%d%d", &N, &M);

    for(int  i=0; i<M; i++) scanf("%*d%d", W+i);

    sort(W, W+M);

    LL k = 1;
    for (; ; k++) {
	if (k/2*k + (k%2) > N) {
	    k--;
	    break;
	}
	if (k==M) break;
    }

    //cout << k << endl;

    LL sum = 0;
    for (int i=0; i<k; i++) sum += W[M-1-i];

    cout << sum << endl;
    
    return 0;
}