#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<sstream>
#include<algorithm>
using namespace std;
typedef long long ll;
ll cal(string str)
{
    ll res=0,dot=-1;
    for(int i=(int)str.size()-1;i>=0;i--)
        if(str[i]=='.')
        {
            dot=(int)str.size()-i;
            break;
        }
    for(int i=0;i<(int)str.size();i++)
        if(str[i]!='.')res=res*10+str[i]-'0';
    return res*(dot!=3 ? 100 : 1);
}
int main()
{
    string str;
    stringstream ss;
    vector<string>price;
    vector<int>part;
    cin>>str;
    for(int i=0;i<(int)str.size();i++)
        if((str[i]<'0' || str[i]>'9') && str[i]!='.')str[i]=' ';
    ss.str(str);
    while(ss>>str)
        price.push_back(str);
    ll res=0;
    for(int i=0;i<(int)price.size();i++)
        res+=cal(price[i]);
    int t=res/100;
    if(t==0)part.push_back(0);
    while(t)
    {
        part.push_back(t%1000);
        t/=1000;
    }
    printf("%d",part.back());
    for(int i=(int)part.size()-2;i>=0;i--)
        printf(".%03d",part[i]);
    t=res%100;
    if(t)printf(".%02d",t);
    return 0;
}