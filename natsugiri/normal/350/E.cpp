#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

typedef long long LL;

int N, K, M, A[400], color[400];
vector<int>B;
bool use[400][400];

int main() {
    scanf("%d%d%d", &N, &M, &K);
    // K>=2
    for (int i=0; i<K; i++) {
	scanf("%d", A+i);
	A[i]--;
	color[A[i]] = 1;
    }

    if (N==K) {
	puts("-1");
	return 0;
    }

    for (int i=0; i<N; i++) if (color[i]==0) B.push_back(i);

    int e = (N-K) + (N-1)*(N-2)/2;

    if (e<M) { 
	puts("-1");
	return 0;
    }

    printf("%d %d\n", A[0]+1, B[0]+1);
    M--;
    use[A[0]][B[0]] = use[B[0]][A[0]] = true;
    
    for (int i=0; i<(int)B.size()-1; i++) {
	printf("%d %d\n", B[i]+1, B[i+1]+1);
	M--;
	use[B[i]][B[i+1]] = use[B[i+1]][B[i]] = true;
    }

    printf("%d %d\n", B[0]+1, A[1]+1);
    M--;
    use[A[1]][B[0]] = use[B[0]][A[1]] = true;

    for (int i=1; i<K-1; i++) {
	printf("%d %d\n", A[i]+1, A[i+1]+1);
	M--;
	use[A[i]][A[i+1]] = use[A[i+1]][A[i]] = true;
    }

    for (int i=0; i<N; i++) {
	for (int j=i+1; j<N; j++) {
	    if (i==A[0] && color[j]==1) continue;
	    if (j==A[0] && color[i]==1) continue;
	    if (M>0 && !use[i][j]) {
		printf("%d %d\n", i+1, j+1);
		M--;
		use[i][j] = use[j][i] = true;
	    }
	}
    }

    return 0;
}