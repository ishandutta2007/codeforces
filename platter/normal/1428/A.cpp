#include <bits/stdc++.h>
using namespace std;

int arr[100000];

int julde(int x) {
    return x>0?x:-x;
}

int main(void) {
    int tc;
    scanf("%d",&tc);
    for(int t=0;t<tc;t++) {
        int x1,y1,x2,y2;
        scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
        if (x1==x2||y1==y2) {
            printf("%d\n",julde(x1-x2)+julde(y1-y2));
        }
        else {
            printf("%d\n",julde(x1-x2)+julde(y1-y2)+2);
        }
    }
}