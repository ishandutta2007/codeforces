#include <iostream>

using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    while(t--){
        int x, y;
        scanf("%d %d", &x, &y);
        printf("%d %d\n", x-1, y);
    }
}