#include <bits/stdc++.h>

#define ll long long
#define pb push_back

using namespace std;

int main()
{
    int n;
    scanf("%i",&n);
    vector<int> a(n);
    for(int i=0;i<n;i++)
    {
        scanf("%i",&a[i]);
    }
    vector<vector<int> > prefix(2,vector<int>(n)),jump(2,vector<int>(2*n+1,INT_MAX-1));
    for(int i=0;i<n;i++)
    {
        int tr=a[i]-1;
        if(i!=0)
        {
            prefix[0][i]=prefix[0][i-1];
            prefix[1][i]=prefix[1][i-1];
        }
        prefix[tr][i]++;
        jump[tr][prefix[tr][i]]=i;
    }
    //printf("Napravio!\n");
    vector<pair<int,int> > res;
    for(int t=1;t<=n;t++)
    {
        int next=0;
        int s1=0,s2=0;
        bool ok=true;
        int s=-1;
        while(next<n)
        {
            vector<int> cnt(2);
            if(next!=0)
            {
                //printf("%i\n",next);
                cnt[0]=prefix[0][next-1];
                cnt[1]=prefix[1][next-1];
            }
            int jmp=min(jump[0][cnt[0]+t],jump[1][cnt[1]+t]);
            next=jmp+1;
            if(jmp<n)
            {
                if(a[jmp]==1)
                {
                    s1++;
                    if(next==n&&s1>s2)
                        s=s1;
                }
                else
                {
                    s2++;
                    if(next==n&&s2>s1)
                        s=s2;
                }
            }
        }
        if(next!=n)
            ok=false;
        if(s==-1)
            ok=false;
        if(ok)
        res.pb({s,t});
    }
    sort(res.begin(),res.end());
    printf("%i\n",res.size());
    for(auto p:res)
    {
        printf("%i %i\n",p.first,p.second);
    }
    return 0;
}