#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
string a,b,c;
int main()
{
    ios::sync_with_stdio(false);
    cin>>a>>b;
    int cnt=0;
    for(int i=0;i<a.size();i++)
    {
        cnt+=(a[i]!=b[i]);
    }
    if(cnt%2)cout<<"impossible"<<endl;
    else
    {
        int tot=0;
        for(int i=0;i<a.size();i++)
        {
            if(a[i]==b[i])
            {
                c+=a[i];
            }
            else
            {
                tot++;
                if(tot<=cnt/2)
                {
                    c+=a[i];
                }
                else
                {
                    c+=b[i];
                }
            }
        }
        cout<<c<<endl;
    }
}