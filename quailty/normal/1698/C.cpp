#include<bits/stdc++.h>
using namespace std;
const int MAXN=200005;
int solve()
{
    int n;
    scanf("%d",&n);
    vector<int> pos,neg;
    int zero=0;
    for(int i=0;i<n;i++)
    {
        int a;
        scanf("%d",&a);
        if(a>0)pos.push_back(a);
        else if(a<0)neg.push_back(a);
        else zero++;
    }
    if(pos.size()>=3u || neg.size()>=3u)
        return 0*printf("NO\n");
    vector<int> a(min(3,zero),0);
    a.insert(a.end(),pos.begin(),pos.end());
    a.insert(a.end(),neg.begin(),neg.end());
    set<int> st(a.begin(),a.end());
    for(int i=0;i<(int)a.size();i++)
        for(int j=0;j<i;j++)for(int k=0;k<j;k++)
            if(!st.count(a[i]+a[j]+a[k]))return 0*printf("NO\n");
    return 0*printf("YES\n");
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)solve();
    return 0;
}