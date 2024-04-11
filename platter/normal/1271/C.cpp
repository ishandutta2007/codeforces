#include <cstdio>
#include <algorithm>
using namespace std;

int main(void) {
    int n,sx,sy;
    scanf("%d %d %d\n",&n,&sx,&sy);
    int left=0;
    int right=0;
    int up=0;
    int down=0;
    for(int i=0;i<n;i++) {
        int x,y;
        scanf("%d %d\n",&x,&y);
        if (x<sx) {
            left+=1;
        }
        if (x>sx) {
            right+=1;
        }
        if (y<sy) {
            down+=1;
        }
        if (y>sy) {
            up+=1;
        }
    }
    int ret=max(max(left,right),max(down,up));
    printf("%d\n",ret);
    if (ret==left) {
        printf("%d %d",sx-1,sy);
    }
    else if (ret==right) {
        printf("%d %d",sx+1,sy);
    }
    else if (ret==down) {
        printf("%d %d",sx,sy-1);
    }
    else if (ret==up) {
        printf("%d %d",sx,sy+1);
    }
    return 0;
}