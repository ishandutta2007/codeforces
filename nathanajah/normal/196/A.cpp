#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
using namespace std;

string s;
int i;
stack <char> hasil;
int sz;
string tmp;

int main()
{
    cin >> s;
    sz=0;
    for (i=0;i<s.length();++i)
    {
        if (sz>0)
        {
            while (hasil.top()<s[i])
            {
                hasil.pop();
                --sz;
                if (sz==0)
                    break;
            }
        }
        hasil.push(s[i]);
        ++sz;
    }
    while (sz>0)
    {
        tmp.append(1,hasil.top());
        --sz;
        hasil.pop();
    }
    for (i=tmp.length()-1;i>=0;--i)
        printf("%c",tmp[i]);
    printf("\n");
}