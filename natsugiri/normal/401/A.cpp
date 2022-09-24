#include<cstdio>
#include<algorithm>
using namespace std;


int main() {
    int N, M;
    scanf("%d%d", &N, &M);
    int sum = 0;
    for (int i=0; i<N; i++) {
	int a;
	scanf("%d", &a);
	sum += a;
    }
    
    printf("%d\n", (abs(sum) + M-1) / M);

    return 0;
}