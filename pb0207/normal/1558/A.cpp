#include<bits/stdc++.h>
using namespace std;

int T,a,b;

vector<int>ans;

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&a,&b);
        int n=(a+b)/2,t=a+b-n*2;
        ans.clear();
        for(int m=0;m<=a+b;m++)
        {
            int d1=n+m-a,d2=n+t-m-b;
            d2=-d2;
            if(d1%2||d2%2)
                continue;
            if(d1/2!=d2/2)
                continue;
            int x=d1/2;
            if(x<0||n-x<0||m-x<0||n-m+x+t<0)
                continue;
            ans.push_back(m);
        }
        swap(a,b);
        n=(a+b)/2,t=a+b-n*2;
        for(int m=0;m<=a+b;m++)
        {
            int d1=n+m-a,d2=n+t-m-b;
            d2=-d2;
            if(d1%2||d2%2)
                continue;
            if(d1/2!=d2/2)
                continue;
            int x=d1/2;
            if(x<0||n-x<0||m-x<0||n-m+x+t<0)
                continue;
            ans.push_back(m);
        }
        sort(ans.begin(),ans.end());
        ans.resize(unique(ans.begin(),ans.end())-ans.begin());
        printf("%d\n",ans.size());
        for(int i=0;i<ans.size();i++)
            printf("%d%c",ans[i]," \n"[i+1==ans.size()]);
    }
}