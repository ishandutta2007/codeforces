#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<set>
using namespace std;
set<string>st;
int main()
{
    ios::sync_with_stdio(false);
    string str;
    int res=0;
    while(getline(cin,str))
    {
        int ty;
        if(str[0]=='+')ty=0;
        else if(str[0]=='-')ty=1;
        else ty=2;
        if(ty<2)
        {
            str=str.substr(1);
            if(ty==0)st.insert(str);
            else st.erase(str);
        }
        else
        {
            int loc=0;
            while(str[loc]!=':')loc++;
            str=str.substr(loc+1);
            res+=(int)str.length()*st.size();
        }
    }
    printf("%d\n",res);
    return 0;
}