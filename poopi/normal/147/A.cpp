//In the name of God
#include <iostream>
#include <cstdio>
#include <cctype>
#include <vector>
using namespace std;

int main()
{
    string r;
    vector<string> all;
    int c;
    while(1)
    {
        c=getchar();
        if(c=='\n' or c==EOF)
        {
            if(r.length()!=0)
                all.push_back(r);
            break;
        }
        else if(isspace(c))
        {
            if(r.length()!=0)
            all.push_back(r);
            r="";
        }
        else if(c=='.' or c==',' or c=='!' or c=='?')
        {
            if(r.length()!=0)
                all.push_back(r);
            r="";
            string add=" ";
            add[0]=c;
            all.push_back(add);
        }
        else
        {
            string add=" ";
            add[0]=c;
            r=r+add;
        }
    }
    //for(int i=0;i<all.size();++i)
        //cerr<<all[i]<<endl;
    for(int i=0;i<all.size();++i)
    {
        if(i==all.size()-1)
        {
            cout<<all[i];
            break;
        }
        if(all[i+1]=="?" or all[i+1]=="!" or all[i+1]=="." or all[i+1]==",")
            cout<<all[i];
        else
            cout<<all[i]<<" ";
    }
    return 0;
}