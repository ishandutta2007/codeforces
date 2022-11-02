#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <string>
#include <string.h>
#include <vector>
#include <map>
#include <stack>
#include <queue>
using namespace std;

int n;
int a[7];
int i;
int banyak;
int sudah;

int main()
{
    scanf("%d",&n);
    for (i=0;i<7;i++)
        scanf("%d",&a[i]);
    sudah=0;
    i=0;
    while (sudah<n)
    {
        sudah+=a[i];
        i=(i+1)%7;
        banyak++;
    }
    if (i==0)
        i=7;
    printf("%d\n",i);
}