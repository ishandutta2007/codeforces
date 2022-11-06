#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<string>
#include<map>
using namespace std;
map<string,string>p,l;
int main()
{
    ios::sync_with_stdio(false);
    int q;
    cin>>q;
    string a,b;
    while(q--)
    {
        cin>>a>>b;
        if(l.find(a)==l.end())
        {
            p[a]=b;
            l[b]=a;
        }
        else
        {
            //cout<<l[a]<<endl;
            p[l[a]]=b;
            l[b]=l[a];
            p.erase(a);
        }
    }
    cout<<p.size()<<endl;
    for(map<string,string>::iterator itr=p.begin();itr!=p.end();itr++)
        cout<<itr->first<<" "<<itr->second<<endl;
    return 0;
}