#include <stdio.h>
#include <iostream>
#include <math.h>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
using namespace std;

int main()
{
    string s;
    int i;
    long long ret;
    long long p,l;
    p=1;l=1;
    int n;
    scanf("%d",&n);
    for (i=0;i<n;++i)
    {
        cin >> s;
        if (s=="UL" || s=="DR")
            ++l;
        else if (s=="UR" ||s=="DL")
            ++p;
        else
        {
            ++p;
            ++l;
        }
    }
    printf("%I64d\n",p*l);
}