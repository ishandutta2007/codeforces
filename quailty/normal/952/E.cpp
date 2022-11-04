#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,cnt[2]={0,0};
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        string name,type;
        cin>>name>>type;
        if(type=="hard")cnt[0]++;
        else cnt[1]++;
    }
    for(int i=1;i<=100;i++)
    {
        int x=i*i/2,y=i*i-i*i/2;
        if(x>=cnt[0] && y>=cnt[1])
            return 0*printf("%d\n",i);
        if(x>=cnt[1] && y>=cnt[0])
            return 0*printf("%d\n",i);
    }
    return 0;
}