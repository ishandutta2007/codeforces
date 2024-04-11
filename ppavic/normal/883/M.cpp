#include <cstdio>
#include <cstdlib>

using namespace std;

int x1,y1,x2,y2;

int main(){
    scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
    if(x1 == x2){
        printf("%d\n", 2 * abs(y1 - y2) + 6);
        return 0;
    }
    if(y1 == y2){
        printf("%d\n",2 * abs(x1 - x2) + 6);
        return 0;
    }
    if(x1 <= x2){
        x2++;
    }
    else{
        x2--;
    }
    if(y1 <= y2){
        y2++;
    }
    else{
        y2--;
    }
    printf("%d\n",abs(x1 - x2) * 2 + abs(y1 - y2) * 2);

}