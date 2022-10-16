#include <iostream>
#include <bits/stdc++.h>

using namespace std;

const int nax=4e5+5;
vector<bool> czy(nax,true);

int main()
{
    int n; cin>>n;
    int a,b;
    a=b=0;
    for(int i=0;i<n;i++)
    {
        int x; cin>>x;
        if(x==1) a++;
        else b++;
    }
    czy[1]=false;
    for(int i=2;i<nax;i++)
    {
        if(czy[i]==true)
        {
            for(int j=2*i;j<nax;j+=i)
            {
                czy[j]=false;
            }
        }
    }
    int suma=0;
    vector<int> ans;
    while(a>0 || b>0)
    {
        if(a==0)
        {
            b--;
            ans.push_back(2);
            suma+=2;
            continue;
        }
        if(b==0)
        {
            a--;
            ans.push_back(1);
            suma++;
            continue;
        }
        if(czy[suma+1]==true)
        {
            a--;
            ans.push_back(1);
            suma+=1;
        }
        else
        {
            b--;
            ans.push_back(2);
            suma+=2;
        }

    }
    for(int i=0;i<ans.size();i++) cout<<ans[i]<<" ";
    return 0;
}