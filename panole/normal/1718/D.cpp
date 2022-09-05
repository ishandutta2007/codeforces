#include<bits/stdc++.h>
using namespace std;

int n,q,p[300010],k,pre[300010],suf[300010],po[300010],a[300010],mis[300010],T,fa[300010],val[300010],L[300010],R[300010],f[300010],g[300010];
vector<int> v[300010];

bool cmpL(int a,int b) {return L[a]<L[b];}
bool cmpR(int a,int b) {return R[a]>R[b];}

void dfs(int x)
{
    //R[x]=min(R[fa[x]],a[fa[x]]);
    R[x]=R[fa[x]],L[x]=0;
    if (a[fa[x]]) R[x]=min(R[x],a[fa[x]]);
    for (int i=0,sz=v[x].size(); i<sz; i++)
        dfs(v[x][i]),L[x]=max(L[x],max(a[v[x][i]],L[v[x][i]]));
}

int main()
{
    scanf("%d",&T);
    while (T--)
    {
        scanf("%d%d",&n,&q),k=0;
        for (int i=1; i<=n; i++) scanf("%d",&p[i]),po[p[i]]=i;
        for (int i=1; i<=n; i++)
        {
            scanf("%d",&a[i]);
            if (!a[i]) mis[++k]=i;
        }
        for (int i=0; i<=n; i++) v[i].clear();
        suf[0]=1,pre[n+1]=n;
        for (int i=1; i<=n; i++) pre[i]=i-1,suf[i]=i+1;
        for (int I=1; I<=n; I++)
        {
            int i=po[I];
            pre[suf[i]]=pre[i];
            suf[pre[i]]=suf[i];
        }
        p[0]=p[n+1]=n+1;
        po[n+1]=0;
        for (int i=1; i<=n; i++)
        {
            int x=pre[i],y=suf[i];
            fa[i]=po[min(p[x],p[y])];
        }
        a[0]=0;
        bool bo=1;
        for (int i=1; i<=n; i++) 
        {
            v[fa[i]].push_back(i);
            if (a[fa[i]]&&a[i]) bo&=(a[fa[i]]>a[i]);
        }
        R[0]=1000000001,dfs(po[n]);
        for (int i=1; i<k; i++) scanf("%d",&val[i]);
        sort(val+1,val+k);
        sort(mis+1,mis+1+k,cmpL);
        set<pair<int,int> > s1,s2;
        s1.clear(),s2.clear();
        for (int i=1; i<=k; i++) s2.insert(make_pair(R[mis[i]],i));
        f[0]=(*s2.begin()).first;
        for (int i=1,pL=0; i<k; i++)
        {
            while (pL<k&&L[mis[pL+1]]<val[i]) 
                pL++,s1.insert(make_pair(R[mis[pL]],pL));
            if (s1.empty())
            {
                for (int j=i; j<k; j++) f[j]=-1;
                break;
            }
            int x=(*s1.begin()).second;
            if (R[mis[x]]<val[i])
            {
                for (int j=i; j<k; j++) f[j]=-1;
                break;
            }
            s1.erase(s1.begin());
            s2.erase(make_pair(R[mis[x]],x));
            f[i]=(*s2.begin()).first;
        }
        sort(mis+1,mis+1+k,cmpR);
        s1.clear(),s2.clear();
        for (int i=1; i<=k; i++) s2.insert(make_pair(-L[mis[i]],i));
        g[k]=-(*s2.begin()).first;
        for (int i=k-1,pR=0; i; i--)
        {
            while (pR<k&&R[mis[pR+1]]>val[i]) 
                pR++,s1.insert(make_pair(-L[mis[pR]],pR));
            if (s1.empty())
            {
                for (int j=i; j; j--) g[j]=1000000001;
                break;
            }
            int x=(*s1.begin()).second;
            if (L[mis[x]]>val[i])
            {
                for (int j=i; j; j--) g[j]=1000000001;
                break;
            }
            s1.erase(s1.begin());
            s2.erase(make_pair(-L[mis[x]],x));
            g[i]=-(*s2.begin()).first;
        }
        while (q--)
        {
            int x; scanf("%d",&x);
            if (!bo) {puts("NO"); continue;}
            int p=lower_bound(val+1,val+k,x)-val;
            if (f[p-1]<x||g[p]>x) {puts("NO"); continue;}
            puts("YES");
        }
    }
    return 0;
}