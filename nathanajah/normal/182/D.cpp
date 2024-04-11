#include <stdio.h>
#include <iostream>
#include <math.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <vector>
#include <stdlib.h>
#include <map>
#include <stack>
#include <queue>
#include <deque>
using namespace std;

string s1,s2;
int i,j;
vector <int> divisor1,divisor2;
vector <int> commdiv;
int n,m;
int res;
bool masih;
string ceknow;
int batas;

int main()
{
    cin >> s1;
    n=s1.length();
    cin >> s2;
    m=s2.length();
    batas=(int)floor(sqrt(n));
    for (i=1;i<=batas;++i)
        if (n%i==0)
        {
            divisor1.push_back(i);
            if (i*i!=n)
                divisor1.push_back(n/i);
        }
    batas=(int)floor(sqrt(m));
    for (i=1;i<=batas;++i)
        if (m%i==0)
        {
            divisor2.push_back(i);
            if (i*i!=m) 
                divisor2.push_back(m/i);
        }
    sort(divisor1.begin(),divisor1.end());
    sort(divisor2.begin(),divisor2.end());
    i=0; j=0;
    commdiv.push_back(0);
    while (i<divisor1.size() && j<divisor2.size())
    {
        if (divisor1[i]==divisor2[j])
        {
            commdiv.push_back(divisor1[i]);
            ++i;
            ++j;
        }
        else if (divisor1[i]>divisor2[j])
            ++j;
        else
            ++i;
    }
    for (i=1;i<commdiv.size();++i)
    {
        masih=true;
        for (j=commdiv[i-1];j<commdiv[i];++j)
            ceknow.append(1,s1[j]);
        for (j=0;j<n;++j)
            if (s1[j]!=ceknow[j%commdiv[i]])
            {
                masih=false;
            }
        for (j=0;j<m;++j)
            if (s2[j]!=ceknow[j%commdiv[i]])
                masih=false;
        if (masih)
            ++res;
    }
    printf("%d\n",res);
}