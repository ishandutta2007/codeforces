#include <cstdio>
using namespace std;

int main(void) {
    int tc;
    scanf("%d\n",&tc);
    for(int t=0;t<tc;t++) {
        int r,c;
        scanf("%d %d\n",&c,&r);
        bool allp=true;
        bool alla=true;
        bool side=false;
        bool corner=false;
        bool left=true;
        bool right=true;
        bool up=true;
        bool down=true;
        bool garoarr[60];
        bool seroarr[60];
        for(int i=0;i<60;i++) {
            garoarr[i]=true;
            seroarr[i]=true;
        }
        for(int i=0;i<c;i++) {
            for(int j=0;j<r;j++) {
                char x;
                scanf("%c",&x);
                if (x=='A') {
                    allp=false;
                    if (i==0||i==c-1||j==0||j==r-1) {
                        side=true;
                    }
                    if ((i==0&&j==0)||(i==0&&j==r-1)||(i==c-1&&j==0)||(i==c-1&&j==r-1)) {
                        corner=true;
                    }
                }
                if (x=='P') {
                    alla=false;
                    if (i==0) {
                        up=false;
                    }
                    if (i==c-1) {
                        down=false;
                    }
                    if (j==0) {
                        left=false;
                    }
                    if (j==r-1) {
                        right=false;
                    }
                    garoarr[i]=false;
                    seroarr[j]=false;
                }
            }
            scanf("\n");
        }
        bool line=false;
        for(int i=0;i<c;i++) {
            if (garoarr[i]) {
                line=true;
            }
        }
        for(int i=0;i<r;i++) {
            if (seroarr[i]) {
                line=true;
            }
        }
        if (allp) {
            printf("MORTAL\n");
        }
        else if (alla) {
            printf("0\n");
        }
        else if (up||down||left||right) {
            printf("1\n");
        }
        else if (corner||line) {
            printf("2\n");
        }
        else if (side) {
            printf("3\n");
        }
        else {
            printf("4\n");
        }
    }
    return 0;
}