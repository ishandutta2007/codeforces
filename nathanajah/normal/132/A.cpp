#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <stack>
#include <deque>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;


string reverse(string a)
{
    string ret;
    int i;
    for (i=a.length()-1;i>=0;i--)
        ret=ret+a[i];
    return ret;
}

string inttobin(int x)
{
    string ret;
    char temp;
    int temp2;
    while (x>0)
    {
        temp2=x%2;
        x=x/2;
        temp=temp2+'0';
        ret=temp+ret;
    }
    while (ret.length()<8)
        ret='0'+ret;
    return ret;
}

int bintoint(string x)
{
    int ret;
    int temp;
    int i;
    for (i=0;i<x.length();i++)
    {
        temp=x[i]-'0';
        ret=2*ret+temp;
    }
    return ret;
}
string s;
int i;
int asc;
int asclast;
int revlast;
int rev;
int jadi;

int main()
{
    string s;
    getline(cin,s);
    asclast=0;
    revlast=0;
    for (i=0;i<s.length();i++)
    {
        asc=s[i];
      //  cout << asc << "\n";
      //  cout << inttobin(asc) << "|";
      //  cout << reverse(inttobin(asc));
        rev = bintoint(reverse(inttobin(asc)));
      //  cout << "R" << rev << "\n";
        jadi=revlast-rev;
        jadi=jadi%256;
        while (jadi<0)
            jadi=jadi+256;
        printf("%d\n",jadi);
        revlast=rev;
        asclast=asc;
    }
}