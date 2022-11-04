#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
vector<int>res;
int main()
{
    int n;
    scanf("%d",&n);
    res.clear();
    for(int i=1;i<=n;i++)
    {
        res.push_back(1);
        while(1)
        {
            int u=res.back();
            res.pop_back();
            if(!res.empty() && res.back()==u)res.back()++;
            else
            {
                res.push_back(u);
                break;
            }
        }
    }
    for(int i=0;i<(int)res.size();i++)
        printf("%d ",res[i]);
    return 0;
}