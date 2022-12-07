#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<string>
#include<cmath>
#include<cctype>
#include<ctime>
#include<bitset>
using namespace std;
const int maxlongint=2147483647;
const int inf=1000000000;
int main()
{
    int i;
    char p[10],f[10];
    scanf("%d%s%s",&i,p,f);
    if(f[0]=='m')
    {
        if(i==31)
            cout<<7<<endl;
        else
            if(i==30)
                cout<<11<<endl;
            else
                cout<<12<<endl;
    }
    else
    {
        if(i==5||i==6)
            cout<<53<<endl;
        else
            cout<<52<<endl;
    }
}