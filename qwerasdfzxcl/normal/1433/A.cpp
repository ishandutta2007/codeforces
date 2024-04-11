#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    for (int i=0;i<t;i++){
        int x;
        scanf("%d", &x);
        int num1=x%10, num2=1;
        while (x/10!=0){
            x /= 10;
            num2 += 1;
        }
        printf("%d\n", (num1-1)*10+(num2)*(num2+1)/2);
    }
    return 0;
}