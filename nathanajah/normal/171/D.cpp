#include <stdio.h>
#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <deque>
#include <map>
#include <vector>
using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    if (n==1)
        printf("2\n");
    else if (n==3)
        printf("1\n");
    else if (n==4)
        printf("2\n");
    else if (n==2)
        printf("3\n");
    else
        printf("1\n");
}