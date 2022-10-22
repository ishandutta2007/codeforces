#include<bits/stdc++.h>
using namespace std;

const int N=2e3+1e2+7;

int T,n,a[N];

vector<int>ans;

void rev(int x)
{
    assert(x&1);
    ans.push_back(x);
    reverse(a+1,a+x+1);
}

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        bool ok=1;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            ok&=((i-a[i])%2==0);
        }
        if(!ok)
        {
            puts("-1");
            continue;
        }
        ans.clear();
        for(int p=n;p>=2;p-=2)
        {
            int pn,pn1;
            for(int i=1;i<=n;i++)
                if(a[i]==p)
                    pn=i;
            rev(pn);
            for(int i=1;i<=n;i++)
                if(a[i]==p-1)
                    pn1=i;
            rev(pn1-1);
            rev(pn1+1);
            rev(3);
            rev(p);
        }
        printf("%d\n",ans.size());
        for(int i=0;i<ans.size();i++)
            printf("%d%c",ans[i]," \n"[i+1==ans.size()]);
        // for(int i=1;i<=n;i++)
        //     printf("%d%c",a[i]," \n"[i==n]);
    }
}