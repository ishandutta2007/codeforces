#include<bits/stdc++.h>
using namespace std;
const int MAXN=400005;
char str[MAXN];
vector<int> loc[26];
vector<pair<int,int> > res;
int main()
{
    int n,k;
    scanf("%d%d%s",&n,&k,str);
    for(int i=0;str[i];i++)
        loc[str[i]-'a'].push_back(i);
    for(int i=0,t=0;i<26;i++)
        for(int j=0;j<(int)loc[i].size();j++,t++)
            if(t>=k)res.push_back({loc[i][j],i});
    sort(res.begin(),res.end());
    for(auto &t:res)
        printf("%c",t.second+'a');
    return 0;
}