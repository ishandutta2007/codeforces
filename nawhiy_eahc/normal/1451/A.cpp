#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    while(t--){
        int n, result=0;
        scanf("%d", &n);
        if(n==1) result = 0;
        else if(n==2) result = 1;
        else if(n==3) result = 2;
        else if(n%2) result = 3;
        else result = 2;
        printf("%d\n", result);
    }
}