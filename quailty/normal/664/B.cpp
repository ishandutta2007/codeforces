#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=105;
string buf;
int n,cnt,ty[MAXN],res[MAXN];
int main()
{
    ty[cnt++]=1;
    while(cin>>buf)
    {
        if(buf=="+")ty[cnt++]=1;
        if(buf=="-")ty[cnt++]=-1;
        if(buf=="=")
        {
            cin>>buf;
            for(int i=0;i<(int)buf.size();i++)
                n=n*10+buf[i]-'0';
        }
    }
    int sum=0;
    for(int i=0;i<cnt;i++)
        sum+=ty[i]*(res[i]=1);
    for(int i=0;i<cnt;i++)
    {
        if(ty[i]>0)
        {
            while(sum<n && res[i]<n)
            {
                sum++;
                res[i]++;
            }
        }
        else
        {
            while(sum>n && res[i]<n)
            {
                sum--;
                res[i]++;
            }
        }
    }
    if(sum!=n)cout<<"Impossible"<<endl;
    else
    {
        cout<<"Possible"<<endl;
        for(int i=0;i<cnt;i++)
        {
            if(i)cout<<" "<<(ty[i]>0 ? "+" : "-")<<" ";
            cout<<res[i];
        }
        cout<<" = "<<n<<endl;
    }
    return 0;
}