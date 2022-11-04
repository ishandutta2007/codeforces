#include<bits/stdc++.h>
using namespace std;
const int MAXN=200005;
char s[MAXN];
int solve()
{
    int n;
    scanf("%d%s",&n,s+1);
    vector<int> odd;
    for(size_t i=1;i<=n;i++)
        if(s[i]=='1')odd.push_back(i);
    if(odd.empty() || odd.size()%2)
        return 0*printf("NO\n");
    printf("YES\n");
    vector<vector<int>> even(odd.size()+1);
    for(size_t i=1,c=0;i<=n;i++)
    {
        if(s[i]=='0')even[c].push_back(i);
        else c++;
    }
    even[0].insert(even[0].begin(),even[odd.size()].begin(),even[odd.size()].end());
    even.pop_back();
    reverse(even[1].begin(),even[1].end());
    even[1].insert(even[1].end(),even[0].begin(),even[0].end());
    for(size_t i=1;i<odd.size();i++)
    {
        vector<int>& path=even[i];
        path.insert(path.begin(),odd[1]);
        path.push_back(odd[i-(i==1)]);
        for(size_t j=0;j+1<path.size();j++)
            printf("%d %d\n",path[j],path[j+1]);
    }
    return 0;
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)solve();
    return 0;
}