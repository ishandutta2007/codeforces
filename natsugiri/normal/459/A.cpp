#include<cstdio>
#include<algorithm>
using namespace std;

int x1, y1, x2, y2;
int main() {
    scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
    
    if (x1 == x2) printf("%d %d %d %d\n", x1+y1-y2, y1, x1+y1-y2, y2);
    else if (y1 == y2) printf("%d %d %d %d\n", x1, y1+x1-x2, x2, y2+x1-x2);
    else if (abs(x1-x2) == abs(y1-y2)) printf("%d %d %d %d\n", x1, y2, x2, y1);
    else puts("-1");

    return 0;
}