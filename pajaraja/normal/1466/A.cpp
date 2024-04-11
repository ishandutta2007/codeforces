#include <bits/stdc++.h>
using namespace std;
map<int,bool> s;
int a[5000];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,res=0; cin>>n;
        for(int i=0;i<n;i++) cin>>a[i];
        s.clear();
        for(int i=0;i<n;i++) for(int j=i+1;j<n;j++)
        {
            int x=abs(a[i]-a[j]);
            if(!s[x]) res++;
            s[x]=true;
        }
        cout<<res<<endl;
    }
}