#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
const int MAXN=100005;
string ress[MAXN*10];
int tot,resv[MAXN*10];
priority_queue<int,vector<int>,greater<int> >q;
int main()
{
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    while(n--)
    {
        string str;
        cin>>str;
        if(str[0]=='i')
        {
            int v;
            cin>>v;
            q.push(v);
            ress[tot]="insert";
            resv[tot]=v;
            tot++;
        }
        else if(str[0]=='g')
        {
            int v;
            cin>>v;
            while(!q.empty() && q.top()<v)
            {
                q.pop();
                ress[tot++]="removeMin";
            }
            if(q.empty() || q.top()>v)
            {
                q.push(v);
                ress[tot]="insert";
                resv[tot]=v;
                tot++;
            }
            ress[tot]="getMin";
            resv[tot]=v;
            tot++;
        }
        else
        {
            if(q.empty())
            {
                q.push(1);
                ress[tot]="insert";
                resv[tot]=1;
                tot++;
            }
            ress[tot++]="removeMin";
            q.pop();
        }
    }
    cout<<tot<<endl;
    for(int i=0;i<tot;i++)
    {
        cout<<ress[i];
        if(ress[i][0]!='r')
            cout<<" "<<resv[i];
        cout<<endl;
    }
    return 0;
}