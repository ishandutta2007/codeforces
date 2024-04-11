#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
#include<set>
using namespace std;

typedef long long LL;


int N;
pair<int,int>A[300010];

int main() {
    scanf("%d", &N);
    for (int i=0; i<N; i++) {
	scanf("%d", &A[i].first);
	A[i].second = i;
    }
    sort(A, A+N);

    int mi = 0;
    for (int i=0; i<N; i++) {
	if (A[i].first < mi) A[i].first = mi;
	mi = A[i].first + 1;
	swap(A[i].first, A[i].second);
    }

    sort(A, A+N);

    for (int i=0; i<N; i++) printf("%d%c", A[i].second, i==N-1 ? '\n':' ');
    

    return 0;
}