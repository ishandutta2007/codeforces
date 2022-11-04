#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<sstream>
#include<algorithm>
using namespace std;
string l,r,s,c;
stringstream ss;
int main()
{
    cin>>s>>c;
    bool flag=(s[0]=='|');
    for(int i=0;i<(int)s.size();i++)
        if(s[i]=='|')s[i]=' ';
    ss.str(s);
    if(!flag)ss>>l>>r;
    else ss>>r;
    for(int i=0;i<(int)c.size();i++)
    {
        if(l.size()<r.size())l.push_back(c[i]);
        else r.push_back(c[i]);
    }
    if(l.size()!=r.size())cout<<"Impossible"<<endl;
    else cout<<l<<'|'<<r<<endl;
    return 0;
}