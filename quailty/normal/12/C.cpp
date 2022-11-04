#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
map<string,int>s;
map<string,int>::iterator itr;
int a[105],cnt[105];
int main()
{
    ios::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    string str;
    for(int i=1;i<=m;i++)
    {
        cin>>str;
        s[str]++;
    }
    int tot=0;
    for(itr=s.begin();itr!=s.end();itr++)
    {
        cnt[++tot]=(*itr).second;
    }
    sort(cnt+1,cnt+tot+1,greater<int>());
    int ans1=0,ans2=0;
    for(int i=1;i<=tot;i++)
    {
        ans1+=cnt[i]*a[i];
        ans2+=cnt[i]*a[n+1-i];
    }
    cout<<ans1<<" "<<ans2<<endl;
    return 0;
}