#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,i;
    cin>>n;
    vector<int> v,b[30];
    int a;
    for (i=0;i<n;i++) {cin>>a; v.push_back(a); 
    for (int j=0;j<30;j++) {if (a%2) b[j].push_back(i); a/=2;} }
    for (i=29;i>=0;i--) if (b[i].size()==1)
    {
        cout<<v[b[i][0]]<<' ';
        for (int j=0;j<n;j++) if (b[i][0]!=j) cout<<v[j]<<' ';
        return 0;
    }
        for (int j=0;j<n;j++)  cout<<v[j]<<' ';
}