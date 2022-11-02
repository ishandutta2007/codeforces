#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <string>
using namespace std;

double eps=1E-9;
double maxi;
double pi=3.1415926535897932384626433832795;
int n,R,r;
double sudutsatu;

int main()
{
    scanf("%d %d %d",&n,&R,&r);
    if (r>R)
        maxi=0;
    else if (2*r>R)
        maxi=1;
    else
    {
    sudutsatu=2*asin((double)r/(R-r));
    maxi=2*pi/sudutsatu;
    }
    if (maxi+eps>n)
        printf("YES\n");
    else
        printf("NO\n");
}