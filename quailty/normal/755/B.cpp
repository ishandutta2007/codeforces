#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<set>
using namespace std;
set<string>mp;
int main()
{
    int n,m;
    cin>>n>>m;
    int cnt[3]={0,0,0};
    string str;
    for(int i=0;i<n;i++)
    {
        cin>>str;
        mp.insert(str);
        cnt[0]++;
    }
    for(int i=0;i<m;i++)
    {
        cin>>str;
        if(mp.find(str)==mp.end())cnt[1]++;
        else cnt[0]--,cnt[2]++;
    }
    if(cnt[2]&1)cnt[1]--;
    return 0*printf("%s",(cnt[0]>cnt[1] ? "YES" : "NO"));
}