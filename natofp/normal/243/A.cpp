#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
cin.tie(0);
    int n; cin>>n;
    int * a=new int[n];
    for(int i=0;i<n;i++) cin>>a[i];
    set<int> m;
    set<int> x;
    int ans=0;
    set<int> glob;
    for(int i=0;i<n;i++)
    {
        x.insert(a[i]);
        set<int>::iterator it;
        it=m.begin();
        while(it!=m.end())
        {
            x.insert((*it)|a[i]); it++;
        }
        m.clear();
        m.insert(x.begin(),x.end());
        glob.insert(x.begin(),x.end());
        x.clear();

    }
    cout<<glob.size();
    return 0;
}