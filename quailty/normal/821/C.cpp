#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
vector<int> stk;
int main()
{
    int n,res=0,t=0;
    scanf("%d",&n);
    for(int i=1;i<=2*n;i++)
    {
        char ty[15];
        scanf("%s",ty);
        if(*ty=='a')
        {
            int x;
            scanf("%d",&x);
            stk.push_back(x);
        }
        else
        {
            t++;
            if(!stk.empty())
            {
                if(stk.back()==t)stk.pop_back();
                else stk.clear(),res++;
            }
        }
    }
    printf("%d\n",res);
    return 0;
}