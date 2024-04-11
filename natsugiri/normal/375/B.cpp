#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

typedef long long LL;

int N, M;
char F[5010][5010];
int one[5010][5010];


int main() {

    scanf("%d%d", &N, &M);
    for (int i=0; i<N; i++) scanf("%s", F[i]);

    for (int i=0; i<N; i++) {
	for (int j=0; j<M; j++) {
	    if (F[i][j] == '1') one[i][j+1] = one[i][j] + 1;
	}
    }


    int ans = 0;
    for (int j=0; j<M; j++) {
	vector<int>v;
	for (int i=0; i<N; i++) v.push_back(one[i][j+1]);
	sort(v.begin(), v.end());

	int mi = M;
	for (int i=0; i<N; i++) {
	    mi = min(mi, v[N-1-i]);
	    ans = max(ans, (i+1)*mi);
	}
    }

    printf("%d\n", ans);
	    
    
    return 0;
}