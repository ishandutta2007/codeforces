#include <iostream>
#include <bits/stdc++.h>

using namespace std;

const int nax=1e5+5;

int n,m,k,q;

set<int> zbior[nax];
int wjakiejskladowejjestem[nax];
vector<int> skladowe[nax];
unordered_map<int,int> krawedzie[nax]; // krawedzie[i][j]=I-ty wierzcholek, J-ty kolor
int rozmiar[nax];

void pre()
{
    cin>>n>>m>>k>>q;
    for(int i=1;i<=n;i++)
    {
        zbior[i].insert(i);
        skladowe[i].push_back(i);
        wjakiejskladowejjestem[i]=i;
        rozmiar[i]=1;
    }
}

void dodaj(int v,int u)
{
    int V=wjakiejskladowejjestem[v];
    int U=wjakiejskladowejjestem[u];
    if(zbior[v].count(U))
    {
        return ;
    }
    skladowe[U].push_back(v);
    rozmiar[U]++;
    zbior[v].insert(U);
}

void debug(int kt)
{
    set<int>::iterator it;
    it=zbior[kt].begin();
    while(it!=zbior[kt].end())
    {
        cout<<*it<<endl;
        it++;
    }

    cout<<"*********************"<<endl;
    for(int i=1;i<=n;i++) cout<<rozmiar[i]<<" ";
    cout<<"*********************"<<endl;
}

void query(int v,int u)
{
    v=wjakiejskladowejjestem[v];
    if(zbior[u].count(v)) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}

void zrob(int v,int u,int kolor)
{
    if(krawedzie[v][kolor]==0)
    {
        krawedzie[v][kolor]=u;
        return;
    }
    int A=wjakiejskladowejjestem[u];
    int B=krawedzie[v][kolor];
    B=wjakiejskladowejjestem[B];
    if(A==B) return;
    if(rozmiar[A]<rozmiar[B]) swap(A,B);
    // dodajemy B do A;
    //for(int i=1;i<=n;i++) cout<<rozmiar[i]<<" ";
    //cout<<A<<" "<<B<<"********************"<<endl;
    for(int i=0;i<skladowe[B].size();i++)
    {
        int akt=skladowe[B][i];
        zbior[akt].erase(B);
        zbior[akt].insert(A);
        if(wjakiejskladowejjestem[akt]==B) wjakiejskladowejjestem[akt]=A;
        skladowe[A].push_back(akt);

    }
    rozmiar[A]+=rozmiar[B];
    rozmiar[B]=0;
}

void add_edge(int u,int v,int kolor)
{
    dodaj(u,v);
    dodaj(v,u);
    zrob(u,v,kolor);
    zrob(v,u,kolor);
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    pre();
    while(m--)
    {
        //debug(1);
        int x,y,z;
        cin>>x>>y>>z;
        add_edge(x,y,z);
    }
    //debug(1);
    while(q--)
    {
        char zz;
        cin>>zz;
        if(zz=='?')
        {
            int x,y; cin>>x>>y;
            query(x,y);
        }
        else
        {
            int x,y,z; cin>>x>>y>>z;
            add_edge(x,y,z);
        }
    }
    return 0;
}