#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{

    int h1,a1,c1;
    int h2,a2;
    cin>>h1>>a1>>c1;
    cin>>h2>>a2;
    int ans=0;
    vector<string> res;
    while(1)
    {
        if(a1>=h2) {ans++; res.push_back("STRIKE"); break;}
        else
        {
            if(h1>a2)
            {
                {ans++; h2-=a1; res.push_back("STRIKE");}
            }
            else
            {
                {ans++; h1+=c1; res.push_back("HEAL");}
            }
        }
        h1-=a2;
    }
    cout<<ans<<endl;
    for(int i=0;i<ans;i++) cout<<res[i]<<endl;
    return 0;
}