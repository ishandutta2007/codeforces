#include<bits/stdc++.h>
using namespace std;
const int MAXN=105;
string str[MAXN],rev[MAXN];
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>str[i];
        rev[i]=str[i];
        reverse(rev[i].begin(),rev[i].end());
    }
    vector<pair<int,int>> res;
    int mid=-1;
    for(int i=0;i<n;i++)
    {
        if(str[i]==rev[i])
            mid=i;
        for(int j=i+1;j<n;j++)
            if(str[i]==rev[j])
                res.emplace_back(i,j);
    }
    printf("%d\n",(2*(int)res.size()+(mid>=0))*m);
    for(int i=0;i<(int)res.size();i++)
        cout<<str[res[i].first];
    if(mid>=0)cout<<str[mid];
    for(int i=(int)res.size()-1;i>=0;i--)
        cout<<str[res[i].second];
    return 0;
}