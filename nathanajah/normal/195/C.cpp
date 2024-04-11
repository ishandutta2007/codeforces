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
#include <map>
#include <deque>
using namespace std;


string s,s2;
int n;
int i,j;
stack <int> tmp;
vector <int> b,e;
vector <string> ex;
vector <string> message;
string lempar;
int llempar;
int mini,nummin;

int main()
{
    scanf("%d",&n);
    getline(cin,s);
    for (i=0;i<n;++i)
    {
        s2="";
        getline(cin,s);
        for (j=0;j<s.length();++j)
        {
            if (s[j]=='"')
                break;
            if (s[j]!=' ')
                s2.append(1,s[j]);
        }
        if (s[j]=='"')
        {
            s2.append(1,s[j]);
            ++j;
            while (s[j]!='"')
            {
                s2.append(1,s[j]);
                ++j;
            }
            while (j<s.length())
            {
                if (s[j]!=' ')
                    s2.append(1,s[j]);
                ++j;
            }
        }
        if (s2.length()==0)
            continue;
        if (s2[1]=='r')
            tmp.push(i);
        else if (s2[1]=='h')
        {
            j=6;
            lempar="";
            while (s2[j]!=')')
            {
                lempar.append(1,s2[j]);
                ++j;
            }
            llempar=i;
        }
        else
        {
            b.push_back(tmp.top());
            tmp.pop();
            e.push_back(i);
            s="";
            j=6;
            while (s2[j]!=',')
            {
                s.append(1,s2[j]);
                ++j;
            }
            ex.push_back(s);
            ++j;
            ++j;
            s="";
            while (s2[j]!='"')
            {
                s.append(1,s2[j]);
                ++j;
            }
            message.push_back(s);
        }
    }
    mini=2000000000;
    for (i=0;i<ex.size();++i)
    {
        if (b[i] < llempar && llempar<e[i])
        {
            if (lempar==ex[i])
            {
                if (e[i]<mini)
                {
                    mini=e[i];
                    nummin=i;
                }
            }
        }
    }
    if (mini==2000000000)
        printf("Unhandled Exception\n");
    else
        cout << message[nummin] << "\n";
}