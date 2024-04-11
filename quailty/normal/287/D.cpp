#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
deque<int>dq;
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        dq.push_back(i+1);
    for(int i=2;i<=n;i++)
    {
        for(int j=(n-1)/i;j>0;j--)
            swap(dq[(j-1)*i],dq[j*i]);
        dq.push_back(dq.front());
        dq.pop_front();
    }
    for(int i=0;i<n;i++)
        printf("%d ",dq[i]);
    return 0;
}