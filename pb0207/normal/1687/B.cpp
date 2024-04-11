#include<bits/stdc++.h>
using namespace std;

const int N=1e6+1e3+7;

typedef long long ll;

int T,n,m;

char s[N];

typedef pair<int,int> pii;

pii w[N];

int qry()
{
    printf("? ");
    puts(s+1);
    fflush(stdout);
    int ans=0;
    scanf("%d",&ans);
    return ans;
}

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=m;j++)
            if(i==j)
                s[j]='1';
            else
                s[j]='0';
        int ww=qry();
        w[i]=pii(ww,i);
    }
    sort(w+1,w+m+1);
    for(int i=1;i<=m;i++)
        s[i]='0';
    int la=0;
    for(int i=1;i<=m;i++)
    {
        auto [y,x]=w[i];
        s[x]='1';
        int val=qry();
        if(val-la==y)
            la=val;
        else
            s[x]='0';
    }
    printf("! %d\n",la);
    fflush(stdout);
}