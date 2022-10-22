#include<bits/stdc++.h>
using namespace std;

const int N=1e6+1e3+7;

int T,c,d;

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&c,&d);
        if((c+d)&1)
            puts("-1");
        else
        {
            if(!c&&!d)
                puts("0");
            else if(abs(c)==abs(d))
                puts("1");
            else
                puts("2");
        }
    }
}