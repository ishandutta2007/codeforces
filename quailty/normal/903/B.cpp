#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int h1,a1,c1,h2,a2;
    scanf("%d%d%d%d%d",&h1,&a1,&c1,&h2,&a2);
    vector<string> res;
    while(1)
    {
        if(h2<=a1)
        {
            res.push_back("STRIKE");
            break;
        }
        else
        {
            if(h1<=a2)
            {
                h1+=c1-a2;
                res.push_back("HEAL");
            }
            else
            {
                h1-=a2,h2-=a1;
                res.push_back("STRIKE");
            }
        }
    }
    printf("%d\n",(int)res.size());
    for(auto &t:res)
        printf("%s\n",t.c_str());
    return 0;
}