#include <stdio.h>
#include <algorithm>

#define A first
#define B second
#define mp make_pair

using namespace std;

typedef pair<int,int> pii;
pii arr[3];
int x,y,z;

int main() {
    int i,j;
    for(i=0;i<3;i++) {
        scanf("%d",&arr[i].A);
        arr[i].B = i;
    }
    x = y = z = 0;
    while(1) {
        sort(arr,arr+3);
        if(arr[1].A == 0) break;
        if((arr[1].B == 0 && arr[2].B == 1) || (arr[1].B == 1 && arr[2].B == 0)) {
            x++; 
        }else if((arr[1].B == 1 && arr[2].B == 2) || (arr[1].B == 2 && arr[2].B == 1)) {
            y++;
        }else {
            z++;
        }
        arr[1].A--;
        arr[2].A--;
    }
    if(arr[2].A != 0) {
        printf("Impossible\n");
    }else {
        printf("%d %d %d\n",x,y,z);
    }
    return 0;
}