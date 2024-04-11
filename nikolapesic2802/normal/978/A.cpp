#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%i",&n);
    int niz[n];
    for(int i=0;i<n;i++)
    {
        scanf("%i",&niz[i]);
    }
    int visited[1001]={};
    stack<int> res;
    for(int i=n-1;i>=0;i--)
    {
        int tr=niz[i];
        //printf("usao za %i\n",tr);
        if(visited[tr]==0)
        {
            //printf("WTF");
            visited[tr]=1;
            res.push(tr);
        }
    }
    printf("%i\n",res.size());
    while(!res.empty())
    {
        printf("%i ",res.top());
        res.pop();
    }
    return 0;
}