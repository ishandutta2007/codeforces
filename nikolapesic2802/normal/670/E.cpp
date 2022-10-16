#include <bits/stdc++.h>

#define ll long long
#define pb push_back

using namespace std;
struct node{
    int parent;
    int rank;
    int left;
    int right;
};
vector<node> niz;
void init(int n)
{
    for(int i=0;i<n;i++)
    {
        if(i==0)
            niz[i].left=-1;
        else
            niz[i].left=i-1;
        if(i==n-1)
            niz[i].right=INT_MAX;
        else
            niz[i].right=i+1;
        niz[i].rank=1;
        niz[i].parent=i;
    }
}
int Find(int x)
{
    //printf("Pozvan za %i, %i\n",x,niz[x].parent);
    if(niz[x].parent!=x)
        niz[x].parent=Find(niz[x].parent);
    return niz[x].parent;
}
void Union(int a,int b)
{
    int sa=Find(a);
    int sb=Find(b);
    if(niz[sa].rank<niz[sb].rank)
    {
        niz[sa].parent=sb;
        niz[sb].left=min(niz[sb].left,niz[sa].left);
        niz[sb].right=max(niz[sb].right,niz[sa].right);
    }
    if(niz[sa].rank>niz[sb].rank)
    {
        niz[sb].parent=sa;
        niz[sa].left=min(niz[sb].left,niz[sa].left);
        niz[sa].right=max(niz[sb].right,niz[sa].right);
    }
    if(niz[sa].rank==niz[sb].rank)
    {
        niz[sb].left=min(niz[sb].left,niz[sa].left);
        niz[sb].right=max(niz[sb].right,niz[sa].right);
        niz[sa].parent=sb;
        niz[sb].rank++;
    }
}
int main()
{
    int n,m,p;
    scanf("%i %i %i",&n,&m,&p);
    p--;
    niz.resize(n);
    init(n);
    char pom[n+1],pom2[m+1];
    scanf("%s",pom);
    scanf("%s",pom2);
    string b=pom;
    int tr=p;
    string s=pom2;
    vector<int> obrisan(n);
    for(int i=0;i<m;i++)
    {
        if(s[i]=='R')
        {
            tr=niz[Find(tr)].right;
        }
        if(s[i]=='L')
        {
            tr=niz[Find(tr)].left;
        }
        if(s[i]=='D')
        {
            int pocetak=tr;
            obrisan[tr]=1;
            if(b[pocetak]==')')
            {
                int l=-1;
                while(l!=0)
                {
                    tr=niz[Find(tr)].left;
                    obrisan[tr]=1;
                    Union(tr,pocetak);
                    if(b[tr]==')')
                        l--;
                    else
                        l++;
                }
                if(niz[Find(pocetak)].right!=INT_MAX)
                {
                    tr=niz[Find(pocetak)].right;
                }
                else
                {
                    tr=niz[Find(pocetak)].left;
                }
            }
            else
            {
                int l=1;
                while(l!=0)
                {
                    tr=niz[Find(tr)].right;
                    obrisan[tr]=1;
                    Union(tr,pocetak);
                    if(b[tr]==')')
                        l--;
                    else
                        l++;
                }
                if(niz[Find(pocetak)].right!=INT_MAX)
                {
                    tr=niz[Find(pocetak)].right;
                }
                else
                {
                    tr=niz[Find(pocetak)].left;
                }
            }
            while(true)
            {
                int l=niz[Find(pocetak)].left;
                if(l!=-1)
                {
                    if(obrisan[l]==1)
                        Union(pocetak,l);
                    else
                    {
                        niz[l].right=niz[Find(pocetak)].right;
                        break;
                    }
                }
                else
                    break;
            }
            while(true)
            {
                int l=niz[Find(pocetak)].right;
                if(l!=-1)
                {
                    if(obrisan[l]==1)
                        Union(pocetak,l);
                    else
                    {
                        niz[l].left=niz[Find(pocetak)].left;
                        break;
                    }
                }
                else
                    break;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        if(!obrisan[i])
            printf("%c",b[i]);
    }
    printf("\n");
    return 0;
}