#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<int> liczby={0,4,8,15,16,23,42};
vector<int> pos[100];

int main()
{
    int n; cin>>n;
    int wsk[7];
    int * a=new int[n+1];
    for(int i=1;i<=n;i++) cin>>a[i];
    memset(wsk,0,sizeof wsk);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=6;j++)
        {
            if(a[i]==liczby[j])
            {
                pos[liczby[j]].push_back(i);
                break;
            }
        }
    }
    int res=0;
    int last=0;
    int roz[7];
    for(int i=1;i<=6;i++)
    {
        roz[i]=pos[liczby[i]].size();
    }
    while(1)
    {
        bool ok = true;
        for(int j=1;j<=6;j++)
        {
            //cout<<j<<" "<<last<<endl;
            while(wsk[j]<roz[j] && pos[liczby[j]][wsk[j]]<=last) wsk[j]++;
            if(wsk[j]==roz[j])
            {
                ok = false;
                break;
            }
            last=pos[liczby[j]][wsk[j]];
            wsk[j]++;
        }
        if(ok==false) break;
        res++;
        last=pos[liczby[1]][wsk[1]-1];
    }
    cout<<n-res*6;

    return 0;
}