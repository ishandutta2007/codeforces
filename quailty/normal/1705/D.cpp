#include<bits/stdc++.h>
using namespace std;
const int MAXN=200005;
char s[MAXN],t[MAXN];
int solve()
{
    int n;
    scanf("%d%s%s",&n,s,t);
    if(s[0]!=t[0] || s[n-1]!=t[n-1])return 0*printf("-1\n");
    vector<int> seg_s,seg_t;
    seg_s.push_back(1),seg_t.push_back(1);
    for(int i=1;i<n;i++)
    {
        if(s[i]!=s[i-1])seg_s.push_back(0);
        seg_s.back()+=1;
        if(t[i]!=t[i-1])seg_t.push_back(0);
        seg_t.back()+=1;
    }
    if(seg_s.size()!=seg_t.size())return 0*printf("-1\n");
    long long res=0;
    for(size_t i=0;i+1<seg_s.size();i++)
    {
        int dif=seg_s[i]-seg_t[i];
        seg_s[i+1]+=dif;
        res+=abs(dif);
    }
    return 0*printf("%lld\n",res);
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)solve();
    return 0;
}