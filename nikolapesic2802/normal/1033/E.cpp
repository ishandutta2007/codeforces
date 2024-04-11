#include <bits/stdc++.h>

#define ll long long
#define pb push_back

using namespace std;
const int mod=1e9+7;
map<int,int> res;
int q(vector<int> s,int l,int r)
{
    if(l==r)
        return 0;
    int h=0;
    vector<int> lol;
    for(int i=l; i<=r; i++)
    {
        lol.pb(s[i]);
    }
    sort(lol.begin(),lol.end());
    for(int i=0; i<lol.size(); i++)
    {
        h=((ll)h*601+lol[i]);
    }
    if(res[h]!=0)
    {
        return res[h];
    }
    printf("? %i\n",r-l+1);
    for(int i=l; i<=r; i++)
    {
        printf("%i ",s[i]);
    }
    printf("\n");
    fflush(stdout);
    int m;
    scanf("%i",&m);
    res[h]=m;
    return m;
}
int q(vector<int> s1,int l1,int r1,vector<int> s2,int l2,int r2)
{
    int m1=q(s1,l1,r1);
    int m2=q(s2,l2,r2);
    vector<int> unija;
    for(int i=l1; i<=r1; i++)
        unija.pb(s1[i]);
    for(int i=l2; i<=r2; i++)
        unija.pb(s2[i]);
    int br=q(unija,0,unija.size()-1);
    assert(m1+m2<=br);
    return br-m1-m2;
}
vector<vector<int> > gen(int n)
{
    vector<int> unutra,ne;
    for(int i=2; i<=n; i++)
    {
        ne.pb(i);
    }
    vector<vector<int> > graf(n+1);
    unutra.pb(1);
    while(!ne.empty())
    {
        int l1=0,l2=0,r1=unutra.size()-1,r2=ne.size()-1;
        while(r1!=l1)
        {
            //printf("Prvi: %i %i\n",l1,r1);
            int mid=(r1+l1)/2;
            if(q(unutra,l1,mid,ne,l2,r2))
            {
                r1=mid;
            }
            else
            {
                l1=mid+1;
            }
        }
        while(r2!=l2)
        {
            //printf("Drugi: %i %i\n",l2,r2);
            int mid=(r2+l2)/2;
            //printf("%i\n",mid);
            if(q(unutra,l1,r1,ne,l2,mid))
            {
                r2=mid;
            }
            else
            {
                l2=mid+1;
            }
        }
        assert(l1==r1&&r2==l2);
#define l1 unutra[l1]
#define l2 ne[l2]
        graf[l1].pb(l2);
        graf[l2].pb(l1);
        //printf("Dodajem %i %i\n",l1,l2);
#undef l1
#undef l2
        vector<int>::iterator it;
        unutra.pb(ne[l2]);
        it=ne.begin();
        for(int i=0; i<l2; i++)
        {
            it++;
        }
        ne.erase(it);
    }
    return graf;
}
int main()
{
    int n;
    scanf("%i",&n);
    if(n==1)
    {
        printf("Y 0\n");
        return 0;
    }
    vector<vector<int> > graf=gen(n);
    vector<int> b1,b2;
    b1.pb(1);
    vector<int> visited(n+1);
    visited[1]=1;
    queue<int> qu;
    qu.push(1);
    while(!qu.empty())
    {
        int tr=qu.front();
        qu.pop();
        for(auto p:graf[tr])
        {
            //printf("Iz %i u %i\n",tr,p);
            if(visited[p]==0)
            {
                if(visited[tr]==1)
                {
                    qu.push(p);
                    visited[p]=2;
                    b2.pb(p);
                }
                else
                {
                    qu.push(p);
                    visited[p]=1;
                    b1.pb(p);
                }
            }
        }
    }
    if(q(b1,0,b1.size()-1)==0&&q(b2,0,b2.size()-1)==0)
    {
        printf("Y %i\n",b1.size());
        for(auto p:b1)
        {
            printf("%i ",p);
        }
        printf("\n");
        fflush(stdout);
        return 0;
    }
    /*printf("NEMA!\n");
    for(auto p:b1)
    {
        printf("b1: %i\n",p);
    }
    for(auto p:b2)
    {
        printf("b2: %i\n",p);
    }*/
    for(int i=0; i<b1.size()-1; i++)
    {
        //printf("Usao za %i-%i\n",i,b1[i]);
        if(q(b1,i,i,b1,i+1,b1.size()-1))
        {
            int l1=i,l2=i+1,r1=i,r2=b1.size()-1;
            while(r2!=l2)
            {
                int mid=(r2+l2)/2;
                if(q(b1,l1,r1,b1,l2,mid))
                {
                    r2=mid;
                }
                else
                {
                    l2=mid+1;
                }
            }
            assert(l1==r1&&r2==l2);
            int poc=b1[l1];
            int kraj=b1[l2];
            vector<int> parent(n+1);
            qu.push(poc);
            parent[poc]=-1;
            while(!qu.empty())
            {
                int tr=qu.front();
                qu.pop();
                for(auto p:graf[tr])
                {
                    if(parent[p]==0)
                    {
                        parent[p]=tr;
                        qu.push(p);
                    }
                }
            }
            vector<int> res;
            int tr=kraj;
            while(parent[tr]!=-1)
            {
                res.pb(tr);
                tr=parent[tr];
            }
            res.pb(tr);
            printf("N %i\n",res.size());
            for(auto p:res)
            {
                printf("%i ",p);
            }
            printf("\n");
            return 0;
        }
    }
    for(int i=0; i<b2.size()-1; i++)
    {
        //printf("Usao za %i-%i\n",i,b2[i]);
        if(q(b2,i,i,b2,i+1,b2.size()-1))
        {
            //printf("Usao!\n");
            int l1=i,l2=i+1,r1=i,r2=b2.size()-1;
            while(r2!=l2)
            {
                int mid=(r2+l2)/2;
                if(q(b2,l1,r1,b2,l2,mid))
                {
                    r2=mid;
                }
                else
                {
                    l2=mid+1;
                }
            }
            assert(l1==r1&&r2==l2);
            int poc=b2[l1];
            int kraj=b2[l2];
            vector<int> parent(n+1);
            qu.push(poc);
            parent[poc]=-1;
            while(!qu.empty())
            {
                int tr=qu.front();
                qu.pop();
                for(auto p:graf[tr])
                {
                    if(parent[p]==0)
                    {
                        parent[p]=tr;
                        qu.push(p);
                    }
                }
            }
            vector<int> res;
            int tr=kraj;
            while(parent[tr]!=-1)
            {
                res.pb(tr);
                tr=parent[tr];
            }
            res.pb(tr);
            printf("N %i\n",res.size());
            for(auto p:res)
            {
                printf("%i ",p);
            }
            printf("\n");
            return 0;
        }
    }
    assert(0);
    return 0;
}