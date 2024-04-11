#include <bits/stdc++.h>
using namespace std;
int ask(string s)
{
    cout<<s<<endl;
    int u;
    cin>>u;
    if (u<=0) exit(0);
 
    return u;
} 
string cur,res;
int n,m,i,j,k,t,t1,u,v,a,b,ca,cb;
int main()
{
    cur="a";
    u=ask("a");
    if (u==300)
    {
        cur="";
        for (i=0;i<300;i++) cur.push_back('b');
        ask(cur);
    }
    for (i=1;i<=u;i++) cur.push_back('a');
    v=ask(cur);
    if (v==u+1)
    {
        for (i=0;i<=u;i++) cur[i]='b';
        cur.pop_back();
        ask(cur);
    }
    else
    {
        n=u+1;
        cb=v;
        ca=n-cb;
        for (i=0;i<n;i++)
        {
            if (i==n-1)
            {
                if (a<ca) res.push_back('a');
                else res.push_back('b');
            }
            else
            {
            cur[i]='b';
            v=ask(cur);
            if (v<cb) {res.push_back('b'); b++;}
            else {res.push_back('a'); a++;}
            cur[i]='a';
            }
        }
        ask(res);
    }
}