#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <string>
#include <vector>
#include <string.h>
#include <stack>
#include <algorithm>
#include <queue>
#include <deque>
using namespace std;

string s1,s2;
int x1[200000],x2[200000];
int i,j;
int cnt41,cnt42,cnt71,cnt72;
int diff;

int main()
{
    cin >> s1;
    cin >> s2;
    for (i=0;i<s1.length();i++)
    {
        if (s1[i]=='4')
        {
            cnt41++;
            x1[i]=4;
        }
        else
        {
            x1[i]=7;
            cnt71++;
        }
    }
    for (i=0;i<s2.length();i++)
    {
        if (s2[i]=='4')
        {
            x2[i]=4;
            cnt42++;
        }
        else
        {
            cnt72++;
            x2[i]=7;
        }
    }
    for (i=0;i<s1.length();i++)
        if (s1[i]!=s2[i])
            diff++;
    printf("%d\n",(diff-abs(cnt42-cnt41))/2+abs(cnt42-cnt41));
    
}