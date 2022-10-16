#include <bits/stdc++.h>
#define ll long long int
using namespace std;

const int nax=4e5+5;
int a[nax];
bool czy[nax];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin>>t;
    while(t--)
    {
        int n; cin>>n;
        for(int i=1;i<=n;i++) cin>>a[i];
        for(int i=1;i<=n;i++) czy[i]=false;
        int ile=1;
        czy[1]=true;
        for(int i=2;i<=n;i++)
        {
            if(a[i]!=a[i-1])
            {
                ile++;
                czy[i]=true;
            }
        }
        int idx=-1;
        for(int i=1;i<=n;i++)
        {
            if(czy[i]==true && (i-1)*2<=n) idx=i-1;
        }
        if(idx==-1)
        {
            cout<<"0 0 0"<<"\n";
            continue;
        }
        int g,s,b;
        g=0; s=0; b=0;
        int val=a[1];
        int koniec=-1;
        for(int i=1;i*2<=n && i<=idx;i++)
        {
            if(a[i]==val)
            {
                g++;
            }
            else
            {
                koniec=i;
                break;
            }
        }
        if(koniec==-1)
        {
            cout<<"0 0 0"<<"\n";
            continue;
        }
        int nast=-1;
        for(int i=koniec;i*2<=n && i<=idx;i++)
        {
            if(s>g && czy[i]==true)
            {
                nast=i;
                break;
            }
            else s++;
        }
        if(nast==-1)
        {
            cout<<"0 0 0"<<"\n";
            continue;
        }
        for(int i=nast;i*2<=n && i<=idx;i++)
        {
            b++;
        }
        if(g<s && g<b && g>0 && b>0 && s>0)
        {
            cout<<g<<" "<<s<<" "<<b<<"\n";
        }
        else cout<<"0 0 0"<<"\n";
    }

    return 0;
}