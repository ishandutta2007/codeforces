#include <bits/stdc++.h>
using namespace std;
const int maxn=100005;
class Segment_Tree
{
    struct Segment
    {
        int begin,end;
        int val;
    };
    private:
        Segment seg[maxn*4];
        int place[maxn];
    public:
        int Create(int l,int r,int t,int *a)
        {
            seg[t].begin=l;
            seg[t].end=r;
            if(l==r)
            {
                place[l]=t;
                return seg[t].val=a[l];
            }
            int mid=l+r>>1;
            return seg[t].val=min(Create(l,mid,t<<1,a),Create(mid+1,r,(t<<1)+1,a));
        }
        int Query(int l,int r,int t)
        {
            if(l==seg[t].begin&&r==seg[t].end)
                return seg[t].val;
            int mid=seg[t].begin+seg[t].end>>1;
            if(l>mid)
                return Query(l,r,(t<<1)+1);
            if(r<=mid)
                return Query(l,r,t<<1);
            return min(Query(l,mid,t<<1),Query(mid+1,r,(t<<1)+1));
        }
        void Replace(int key,int &Val)
        {
            int tmp=place[key]>>1;
            seg[tmp].val=Val;
            while(tmp!=0)
            {
                if(seg[tmp].val==min(seg[tmp>>1].val,seg[(tmp>>1)+1].val))
                    break;
                seg[tmp].val=min(seg[tmp>>1].val,seg[(tmp>>1)+1].val);
                tmp>>=1;
            }
        }
};
Segment_Tree t[8];
int n,m,k,ansl,ansr,a[8][maxn];
int search(int &i)
{
    int l=i,r=n+1;
    while(l<r-1)
    {
        int mid=l+r>>1,sum=0;
        for(int j=1;j<=m;j++)
            sum-=t[j].Query(i,mid,1);
        if(sum>k)
            r=mid;
        else
            l=mid;
    }
    return l;
}
int main()
{
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            scanf("%d",a[j]+i);
            a[j][i]=-a[j][i];
        }
    for(int i=1;i<=m;i++)
        t[i].Create(1,n,1,a[i]);
    ansl=1;
    ansr=1;
    bool c=false;
    int r;
    for(int i=1;i<=n;i++)
    {
        int sum=0;
        for(int j=1;j<=m;j++)sum-=a[j][i];
        if(sum>k)
            continue;
        c=true;
        r=search(i);
        if(r-i+1>ansr-ansl+1)
        {
            ansl=i;
            ansr=r;
        }
    }
    for(int i=1;i<=m;i++)
        printf("%d ",c?(-t[i].Query(ansl,ansr,1)):0);
    return 0;
}