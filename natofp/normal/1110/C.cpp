#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<int> tab={3,7,15,31,63,127,255,511,1023,2047,4095,8191,16383,32767,65535,131071,262143,524287,1048575,2097151,4194303,8388607,16777215,33554431};
vector<int> odp={1,1,5,1,21,1,85,73,341,89,1365,1,5461,4681,21845,1,87381,1,349525,299593,1398101,178481,5592405,1082401};
int ilebit(int x)
{
    int res=0;
    while(x)
    {
        x/=2;
        res++;
    }
    return res;
}

bool xd(int a)
{
    for(int i=0;i<24;i++)
    {
        if(a==tab[i])
        {
            cout<<odp[i]<<endl;
            return true;
        }
    }
    return false;
}

int main()
{
    int q; cin>>q;
    for(int i=1;i<=q;i++)
    {
        int a; cin>>a;
        if(xd(a)==true) continue;
        else cout<<(1<<(ilebit(a)))-1<<endl;
    }
    return 0;
}