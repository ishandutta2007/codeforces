#include <iostream>
#include <bits/stdc++.h>
#define ll long long int
using namespace std;

const int nax=105;
int a[nax];
int pos[nax];
bool used[nax];


void xd(int idx)
{
    used[idx]=true;
    swap(a[idx],a[idx+1]);
    swap(pos[a[idx]],pos[a[idx+1]]);
}

int main()
{
    int q; cin>>q;
    while(q--)
    {
        int n;cin>>n;
        for(int i=1;i<=n;i++) cin>>a[i];
        for(int i=1;i<=n;i++) pos[a[i]]=i;
        for(int i=1;i<=n;i++) used[i]=false;
        for(int i=1;i<=n;i++)
        {
            int akt=pos[i];
            while(akt-1>=1 && used[akt-1]==false && a[akt-1]>a[akt])
            {
                xd(akt-1);
                akt--;
            }

        }
        for(int i=1;i<=n;i++) cout<<a[i]<<" ";
        cout<<endl;

    }
    return 0;
}