#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
string convert(string str,int l,int r)
{
    string res;
    for(int i=0;i<l;i++)
        res.push_back(str[i]);
    for(int i=0;i<3;i++)
        res.push_back('*');
    for(int i=r+1;i<(int)str.size();i++)
        res.push_back(str[i]);
    return res;
}
int main()
{
    int n;
    string str;
    cin>>n>>str;
    while(1)
    {
        bool change=0;
        for(int i=0;i+3<=(int)str.size();i++)
            if(str[i]=='o' && str[i+1]=='g' && str[i+2]=='o')
            {
                int j=i+2;
                while(j+3<=(int)str.size() && str[j+1]=='g' && str[j+2]=='o')j+=2;
                str=convert(str,i,j);
                change=1;
                break;
            }
        if(!change)break;
    }
    cout<<str<<endl;
    return 0;
}