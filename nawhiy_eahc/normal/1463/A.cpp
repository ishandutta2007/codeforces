#include <iostream>

using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    while(t--){
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        if((a+b+c)%9 == 0 && min(a, min(b, c)) >= (a+b+c)/9){
            printf("YES\n");
        }
        else printf("NO\n");
    }
}