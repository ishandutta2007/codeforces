#include <stdio.h>
#include <iostream>
#include <math.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <vector>
#include <stdlib.h>
using namespace std;

int maxi=-1;
string s;
int i,j,k;
int n;
int a1,a2,a3;

int main()
{
    cin >> s;
    n=s.length();
    for (i=1;i<n;++i)
        for (j=i+1;j<n;++j)
        {
            a1=0;
            a2=0;
            a3=0;
            if (i>7 || j-i>7 || n-j>7)
                continue;
            if ((s[0]=='0' && i>1) || (s[i]=='0' && j-i>1) || (s[j]=='0' && n-j>1))
                continue;
            for (k=0;k<i;++k)
                a1=10*a1+(s[k]-'0');
            for (k=i;k<j;++k)
                a2=10*a2+(s[k]-'0');
            for (k=j;k<n;++k)
                a3=10*a3+(s[k]-'0');
            if (a1<=1000000 && a2<=1000000 && a3<=1000000)
                maxi=max(maxi,a1+a2+a3);
        }
    printf("%d\n",maxi);
}