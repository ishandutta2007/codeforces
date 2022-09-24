#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

typedef long long LL;

int N, M, K;
vector<int>A, B;
int main() {
    scanf("%d%d%d", &N, &M, &K);
    for (int i=0; i<N; i++) {
	int t;
	scanf("%d", &t);
	A.push_back(t);
    }
    for (int i=0; i<M; i++) {
	int t;
	scanf("%d", &t);
	B.push_back(t);
    }

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    int p, q;
    p=0; q=0;
    
    for (;;) {
	if (A.size()-p>B.size()-q) {
	    puts("YES");
	    return 0;
	}

	if (int(A.size())==p && int(B.size())==q) break;

	if (int(A.size())==p) q++;
	else if (int(B.size())==q) p++;
	else {
	    if (A[p]<B[q]) p++;
	    else if (A[p]>B[q]) q++;
	    else { p++; q++; }
	}
    }
    
    puts("NO");
    return 0;
}