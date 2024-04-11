#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
#include<deque>
using namespace std;

typedef long long LL;

int N, M, A[110];
vector<int> AU;

int main() {
    scanf("%d%d", &N, &M);
    for (int i=0; i<N; i++) scanf("%d", A+i);
    for (int i=0; i<M; i++) {
	int x;
	scanf("%d", &x);
	x--;
	AU.push_back(A[x]);
	A[x] = 0;
    }

    sort(AU.begin(), AU.end());

    LL ans = 0;
    for (int i=0; i<=M; i++) {
	LL sum = 0;
	for (int j=0; j<N; j++) sum += A[j];
	for (int j=i; j<M; j++) sum += AU[j];
	for (int j=0; j<i; j++) {
	    if (sum > AU[j]) sum *= 2;
	    else sum += AU[j];
	}

	ans = max(ans, sum);
    }

    cout << ans << endl;
    
    return 0;
    
}