#include <cstdio>
#include <algorithm>
using namespace std;

int main(void) {
    int n;
    scanf("%d\n",&n);
    long long black=0;
    long long white=0;
    for(int i=0;i<n;i++) {
        long long x;
        scanf("%lld ",&x);
        if (i%2==0) {
            black+=(x+1)/2;
            white+=x/2;
        }
        else {
            white+=(x+1)/2;
            black+=x/2;
        }
    }
    printf("%lld",min(white,black));
    return 0;
}