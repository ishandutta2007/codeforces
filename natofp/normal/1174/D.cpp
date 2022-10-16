#include <iostream>
#include <bits/stdc++.h>

using namespace std;

const int nax=5e5+5;
int n,x;
vector<bool> czy(nax,true);


int main()
{
    cin>>n>>x;
    int PREF=0;
    vector<int> ans;
    n=(1<<n);
    czy[0]=czy[x]=false;
    int wsk=1;
    while(wsk<n)
    {
        if(czy[wsk]==false)
        {
            wsk++;
            continue;
        }
        int nowa=wsk^PREF;
        ans.push_back(nowa);
        PREF^=nowa;
        czy[PREF]=false;
        czy[PREF^x]=false;
    }
    cout<<ans.size()<<endl;
    for(int i=0;i<ans.size();i++) cout<<ans[i]<<" ";
    return 0;
}