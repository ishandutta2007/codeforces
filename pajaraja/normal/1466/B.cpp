#include <bits/stdc++.h>
#define MAXN 100007
using namespace std;
int a[MAXN];
bool vi[2*MAXN];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,res=0;
        cin>>n;
        for(int i=0;i<n;i++) cin>>a[i];
        for(int i=0;i<n;i++)
        {
            if(!vi[a[i]]) {vi[a[i]]=true; res++; continue;}
            if(!vi[a[i]+1]) {vi[a[i]+1]=true; res++;}
        }
        cout<<res<<endl;
        for(int i=1;i<=2*n+5;i++) vi[i]=false;
    }
}