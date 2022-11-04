#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<sstream>
#include<algorithm>
#include<vector>
using namespace std;
vector<string>in,out;
string str,word;
stringstream ss;
char buf[305];
int main()
{
    int n;
    scanf("%d%s",&n,buf);
    str=buf;
    int now=0;
    while(1)
    {
        if(!now)
        {
            if(str.find('(')!=string::npos)
            {
                out.push_back(str.substr(0,str.find('(')));
                str=str.substr(str.find('(')+1);
            }
            else break;
        }
        else
        {
            if(str.find(')')!=string::npos)
            {
                in.push_back(str.substr(0,str.find(')')));
                str=str.substr(str.find(')')+1);
            }
            else break;
        }
        now^=1;
    }
    if(!now)out.push_back(str);
    else in.push_back(str);
    int res[2]={0,0};
    for(int i=0;i<(int)out.size();i++)
    {
        for(int j=0;j<(int)out[i].size();j++)
            if(out[i][j]=='_')out[i][j]=' ';
        ss.clear();
        ss.str(out[i]);
        while(ss>>word)
            res[0]=max(res[0],(int)word.size());
    }
    for(int i=0;i<(int)in.size();i++)
    {
        for(int j=0;j<(int)in[i].size();j++)
            if(in[i][j]=='_')in[i][j]=' ';
        ss.clear();
        ss.str(in[i]);
        while(ss>>word)
            res[1]++;
    }
    printf("%d %d\n",res[0],res[1]);
    return 0;
}