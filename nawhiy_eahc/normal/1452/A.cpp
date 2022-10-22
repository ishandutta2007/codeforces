#include <iostream>

using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    while(t--){
        int x, y;
        scanf("%d %d", &x, &y);
        int result = 0;
        result += x+y;
        if(x>y+1) result += x-y-1;
        if(y>x+1) result += y-x-1;
        printf("%d\n", result);
    }
}