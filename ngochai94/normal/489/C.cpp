#include <bits/stdc++.h>
using namespace std;

int lis[3001];
int m,s;
int main()
{
    //freopen("input.txt","r",stdin);
    ios::sync_with_stdio(0);
    cin>>m>>s;
    if (m==1 && s==0) cout<<"0 0";
    else if (s<1 || s>9*m) cout <<"-1 -1";
    else
    {
        if (s-9*(m-1)>=1)
        {
            cout<<s+9-9*m;
            for (int i=0;i<m-1;i++) cout <<9;
        }
        else
        {
            cout<<1;
            for (int i=0;i<m-1-(s+7)/9;i++) cout <<0;
            if ((s-1)%9!=0) cout<<(s-1)%9;
            for (int i=0;i<(s-1)/9;i++) cout<<9;
        }
        cout<<' ';
        for (int i=0;i<s/9;i++) cout<<9;
        if (s%9==0) for (int i=0;i<m-s/9;i++) cout<<0;
        else
        {
            cout<<s%9;
            for (int i=0;i<m-s/9-1;i++) cout<<0;
        }
    }
    return 0;
}