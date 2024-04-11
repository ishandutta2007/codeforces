#include <iostream>
#include <bits/stdc++.h>

using namespace std;



int main()
{
    int n; cin>>n;
    int * a=new int[n+1];
    int * b=new int[n+1];
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>>b[i];
    set<int> xd;
    int ile[300000];
    memset(ile,0,sizeof ile);
    for(int i=1;i<=n;i++)
    {
        ile[b[i]]++;
    }
    for(int i=1;i<=n;i++) xd.insert(b[i]);
    set<int>::iterator it;
    set<int>::iterator it2;
    set<int>::iterator it3;
    for(int i=1;i<=n;i++)
    {
        int val=a[i];
        it=xd.lower_bound(n-val);
        it3=xd.end();
        it3--;
        if(*it3<n-val)
        {
            int z=*xd.begin();
            ile[z]--;
            if(ile[z]==0) xd.erase(z);
            cout<<(val+z)%n<<" ";
            continue;
        }
        int z=*it;
        it2=xd.begin();
        int z2=*it2;
        if((val+z)%n<(val+z2)%n)
        {
            ile[z]--;
            if(ile[z]==0) xd.erase(z);
            cout<<(val+z)%n<<" ";
        }
        else
        {
            ile[z2]--;
            if(ile[z2]==0) xd.erase(z2);
            cout<<(val+z2)%n<<" ";
        }
    }
    return 0;
}