#include <cstdio>
#include <algorithm>
using namespace std;

int main(void) {
    int c;
    scanf("%d\n", &c);
    for(int t=0;t<c;t++) {
        int n;
        scanf("%d\n", &n);
        int minie=1000000000;
        int maxis=0;
        for(int i=0;i<n;i++) {
            int s,e;
            scanf("%d %d\n", &s, &e);
            maxis=max(s,maxis);
            minie=min(e,minie);
        }
        printf("%d\n",max(0,maxis-minie));
    }
    return 0;
}