#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        if(b==0)
        {
            if(a)for(int i=0;i<=a;i++)
                printf("0");
            if(c)for(int i=0;i<=c;i++)
                printf("1");
            printf("\n");
        }
        else
        {
            vector<int> res(b+1,1);
            res[0]+=a,res[1]+=c;
            for(int i=0;i<(int)res.size();i++)
                for(int j=0;j<res[i];j++)
                    printf("%d",i%2);
            printf("\n");
        }
    }
    return 0;
}