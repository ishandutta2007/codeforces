#include <bits/stdc++.h>

using namespace std;
int main()
{
    int n;
    scanf("%i",&n);
    priority_queue<int,vector<int>,less<int> > a,b;
    for(int i=0;i<n;i++)
    {
        int x;
        scanf("%i",&x);
        a.push(x);
    }
    for(int i=0;i<n;i++)
    {
        int x;
        scanf("%i",&x);
        b.push(x);
    }
    //printf("%i %i\n",a.top(),b.top());
    long long aa=0,bb=0;
    while(!a.empty()||!b.empty())
    {
        if(a.empty())
        {
            b.pop();
        }
        else
        {
            if(b.empty())
            {
                aa+=a.top();
                a.pop();
            }
            else
            {
                if(a.top()>b.top())
                {
                    aa+=a.top();
                    a.pop();
                }
                else
                {
                    b.pop();
                }
            }
        }
        if(a.empty())
        {
            bb+=b.top();
            b.pop();
        }
        else
        {
            if(b.empty())
            {
                a.pop();
            }
            else
            {
                if(a.top()<b.top())
                {
                    bb+=b.top();
                    b.pop();
                }
                else
                {
                    a.pop();
                }
            }
        }
    }
    printf("%lld\n",aa-bb);
    return 0;
}