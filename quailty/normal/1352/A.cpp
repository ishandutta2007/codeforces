#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n;
        scanf("%d",&n);
        vector<int> res;
        int t=1;
        while(n)
        {
            if(n%10)res.push_back(n%10*t);
            n/=10,t*=10;
        }
        printf("%d\n",(int)res.size());
        for(int i=0;i<(int)res.size();i++)
            printf("%d%c",res[i]," \n"[i+1==(int)res.size()]);
    }
    return 0;
}