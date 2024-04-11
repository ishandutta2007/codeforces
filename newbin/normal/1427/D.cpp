#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define lowbit(x) ((x)&(-(x)))
#define mid ((l+r)>>1)
#define lson rt<<1, l, mid
#define rson rt<<1|1, mid+1, r
#define fors(i, a, b) for(int i = (a); i < (b); ++i)
#define P pair<int,int>
using namespace std;
const int maxn=55;
int n;
int a[maxn];
int b[maxn];
vector<vector<P> >ans;
bool check()
{
    for(int i=1;i<=n;++i) if(a[i]!=i) return 0;
    return 1;
}
int main()
{
    scanf("%d", &n);
    for(int i=1;i<=n;++i) scanf("%d",a+i);
    a[0]=-1e9;
    while(!check())
    {
        int flag=false;
        for(int i=1;i<=n;++i)
        {
            int x=a[i];
            for(int j=i;j<=n;++j)
            {
                int y=a[j];
                if(x==y+1)
                {
                    //printf("%d %d \n",x,y);
                    vector<P>tmp;
                    int tl=i,tr=j;
                    while(a[tl+1]==a[tl]+1) ++tl;
                    while(a[tr-1]==a[tr]-1) --tr;
                    memcpy(b,a,sizeof(b));
                    int p=0;
                    if(i!=1) tmp.pb(P(1,i-1));
                    tmp.pb(P(i,tr-1));
                    tmp.pb(P(tr,j));
                    if(j!=n) tmp.pb(P(j+1,n));
                    ans.pb(tmp);
                    for(int k=tmp.size()-1;k>=0;--k)
                    {
                        int l=tmp[k].first,r=tmp[k].second;
                        //printf("%d %d\n",l,r);
                        for(int z=l;z<=r;++z) a[++p]=b[z];
                    }
                    flag=true;
                }
                if(flag) break;
            }
            if(flag) break;
        }
        //for(int i=1;i<=n;++i) printf("%d ",a[i]);puts("");
    }
    cout<<ans.size()<<'\n';
    for(auto i:ans)
    {
        cout<<i.size();
        for(auto j:i) printf(" %d",j.second-j.first+1);
        puts("");
    }
}