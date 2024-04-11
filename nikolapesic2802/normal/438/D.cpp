#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back

struct SegmentTree{
    int n;
    vector<ll> minn,maxx,sum;
    vector<int> l,r;
    void setlr(int node,int l1,int rr)
    {
        l[node]=l1;
        r[node]=rr;
        if(l1==rr)
            return;
        int mid=(l1+rr)/2;
        setlr(node*2,l1,mid);
        setlr(node*2+1,mid+1,rr);
    }
    void init(int nn)
    {
        n=nn;
        l.resize(4*n);
        r.resize(4*n);
        minn.resize(4*n);
        fill(minn.begin(),minn.end(),LLONG_MAX);
        maxx.resize(4*n);
        sum.resize(4*n);
        setlr(1,0,n-1);
    }
    void prop(int i)
    {
        if(minn[i]==maxx[i])
        {
            ll el=maxx[i];
            int mid=(l[i]+r[i])/2;
            minn[2*i]=el;
            minn[2*i+1]=el;
            maxx[2*i+1]=el;
            maxx[2*i]=el;
            sum[2*i]=(ll)el*(mid-l[i]+1);
            sum[2*i+1]=(ll)el*(r[i]-mid);
        }
    }
    void update(int i)
    {
        sum[i]=sum[2*i]+sum[2*i+1];
        minn[i]=min(minn[2*i],minn[2*i+1]);
        maxx[i]=max(maxx[2*i],maxx[2*i+1]);
    }
    void postavi(int q,int k,int i=1)
    {
        if(l[i]>q||r[i]<q)
            return;
        if(l[i]==r[i])
        {
            minn[i]=k;
            maxx[i]=k;
            sum[i]=k;
            return;
        }
        prop(i);
        postavi(q,k,2*i);
        postavi(q,k,2*i+1);
        update(i);
    }
    void modify(int ql,int qr,int x,int i=1)
    {
        if(l[i]>qr||r[i]<ql||maxx[i]<x)
            return;
        if(l[i]>=ql&&r[i]<=qr&&maxx[i]==minn[i])
        {
            int el=maxx[i];
            el%=x;
            minn[i]=el;
            maxx[i]=el;
            sum[i]=(ll)el*(r[i]-l[i]+1);
            return;
        }
        prop(i);
        modify(ql,qr,x,2*i);
        modify(ql,qr,x,2*i+1);
        update(i);
    }
    ll get(int ql,int qr,int i=1)
    {
        if(l[i]>qr||r[i]<ql)
            return 0;
        if(l[i]>=ql&&r[i]<=qr)
            return sum[i];
        prop(i);
        return get(ql,qr,2*i)+get(ql,qr,2*i+1);
    }
};
int main()
{
    int n,m;
    scanf("%i %i",&n,&m);
    SegmentTree st;
    st.init(n);
    for(int i=0;i<n;i++)
    {
        int a;
        scanf("%i",&a);
        st.postavi(i,a);
    }
    for(int i=0;i<m;i++)
    {
        int t;
        scanf("%i",&t);
        if(t==1)
        {
            int l,r;
            scanf("%i %i",&l,&r);
            l--;
            r--;
            printf("%lld\n",st.get(l,r));
        }
        if(t==2)
        {
            int l,r,x;
            scanf("%i %i %i",&l,&r,&x);
            l--;
            r--;
            st.modify(l,r,x);
        }
        if(t==3)
        {
            int k,x;
            scanf("%i %i",&k,&x);
            k--;
            st.postavi(k,x);
        }
    }
    return 0;
}