#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

string a;
string b;
string c;

int ilea[550], ileb[550], ilec[550];

int wyn1, wyn2;

int ilez[550];

int aktu2;

int main()
{
    cin >> a;
    cin >> b;
    cin >> c;
    for (int i=0; i<a.size(); i++)
    {
        ilea[a[i]]++;
    }
    for (int i=0; i<b.size(); i++)
    {
        ileb[b[i]]++;
    }
    for (int i=0; i<c.size(); i++)
    {
        ilec[c[i]]++;
    }
    for (int aktu1=0; aktu1<(a.size()/b.size()); aktu1++)
    {
        aktu2=0;
        for (char i='a'; i<='z'; i++)
        {
            ilez[i]=ilea[i]-aktu1*ileb[i];
            if (ilez[i]<0)
            {
                aktu2=-1;
                break;
            }
        }
        if (aktu2<0)
        continue;
        aktu2=a.size()+5;
        for (char i='a'; i<='z'; i++)
        {
            if (ilec[i])
            aktu2=min(aktu2, ilez[i]/ilec[i]);
        }
        if (aktu1+aktu2>wyn1+wyn2)
        {
            wyn1=aktu1;
            wyn2=aktu2;
        }
    }
    for (int i=1; i<=wyn1; i++)
    {
        for (int j=0; j<b.size(); j++)
        {
            printf("%c", b[j]);
            ilea[b[j]]--;
        }
    }
    for (int i=1; i<=wyn2; i++)
    {
        for (int j=0; j<c.size(); j++)
        {
            printf("%c", c[j]);
            ilea[c[j]]--;
        }
    }
    for (char i='a'; i<='z'; i++)
    {
        for (int j=0; j<ilea[i]; j++)
        printf("%c", i);
    }
    return 0;
}