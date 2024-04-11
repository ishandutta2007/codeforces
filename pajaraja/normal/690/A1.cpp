#include <stdio.h>
#include <algorithm>
using namespace std;
int main()
{
    int n;
    scanf("%d", &n);
    int sol=n/2;
    if(n%2==1) sol++;
    printf("%d", sol);
    return 0;
}