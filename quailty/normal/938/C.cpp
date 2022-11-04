#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int x;
        scanf("%d",&x);
        if(x==0)
        {
            printf("1 1\n");
            continue;
        }
        vector<int> f;
        for(int i=1;i*i<x;i++)
            if(x%i==0)f.push_back(i);
        bool isok=0;
        for(int i=0;i<(int)f.size();i++)
        {
            int p=f[i],q=x/f[i];
            if(p%2!=q%2)continue;
            int n=(p+q)/2,ndm=(q-p)/2,m=n/ndm;
            if(n/m==ndm)
            {
                printf("%d %d\n",n,m);
                isok=1;
                break;
            }
        }
        if(!isok)printf("-1\n");
    }
    return 0;
}