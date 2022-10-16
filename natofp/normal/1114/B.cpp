#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m,k; cin>>n>>m>>k;
    int * a=new int[n];
    for(int i=0;i<n;i++) cin>>a[i];
    int * b=new int[n];
    for(int i=0;i<n;i++) b[i]=a[i];
    sort(b,b+n);
    int t=n-k*m;
    multiset<int> xd;
    for(int i=t;i<n;i++) xd.insert(b[i]);
    long long int res=0;
    vector<int> ans;
    int ile=0;
    vector<int> pom;
    for(int i=0;i<n;i++)
    {
        if(xd.count(a[i])>=1)
        {
            ile++;
            pom.push_back(a[i]);
            xd.erase(xd.find(a[i]));
            if(ile==m)
            {
                for(int j=0;j<m;j++) res+=pom[j];
                pom.clear();
                ile=0;
                ans.push_back(i+1);
            }
        }
    }
    cout<<res<<endl;
    for(int i=0;i<ans.size()-1;i++) cout<<ans[i]<<" ";
    return 0;
}