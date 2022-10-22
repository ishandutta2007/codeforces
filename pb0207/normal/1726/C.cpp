#include<bits/stdc++.h>
using namespace std;

const int N=1e6+1e3+7;

int T;

int n;

char s[N];

int to[N],p[N],fa[N];

int find(int x)
{
    return x==fa[x]?x:fa[x]=find(fa[x]);
}

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        scanf("%s",s+1);
        vector<int>st;
        for(int i=1;i<=n*2+1;i++)
            fa[i]=i;
        s[n*2+1]='(';
        for(int i=1;i<=n*2;i++)
        {
            if(s[i]=='(')
                st.push_back(i);
            else
            {
                if(s[i+1]=='(')
                    fa[find(st.back())]=find(i+1);
                st.pop_back();
            }
        }
        int ans=0;
        for(int i=1;i<=n*2+1;i++)
            if(fa[i]==i&&s[i]=='(')
                ans++;
        printf("%d\n",ans);
    }
}