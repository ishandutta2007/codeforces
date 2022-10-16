#include <iostream>
#include <bits/stdc++.h>
#define ll long long int
using namespace std;
 
int ROZMIAR;
 
struct xd
{
    int a,b,c,d;
};
int n,m;
 
int tab[5][111];
bool czy[111];
 
bool por(int id1,int id2)
{
    // cout<<"XD"<<endl;
    vector<int> a;
    vector<int> b;
    for(int i=1;i<=ROZMIAR;i++)
    {
        a.push_back(tab[i][id1]);
        b.push_back(tab[i][id2]);
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    for(int i=a.size()-1;i>=0;i--)
    {
        if(a[i]>b[i]) return true;
        if(a[i]<b[i]) return false;
    }
    return id1<id2;
}
 
int val(int idx)
{
    int res=0;
    for(int i=1;i<=4;i++)
    {
        res=max(res,tab[i][idx]);
    }
    return res;
}
 
void solve(vector<int> idx,int pom)
{
    int res=0;
    int ile=idx.size();
    int wszystko=1;
    for(int i=0;i<ile;i++) wszystko*=pom;
    for(int i=0;i<wszystko;i++)
    {
        int s1,s2,s3,s4;
        int j=i;
        s1=j%pom;
        j/=pom;
        s2=j%pom;
        j/=pom;
        s3=j%pom;
        j/=pom;
        s4=j%pom;
        j/=pom;
        int pot=0;
        for(int j=1;j<=pom;j++)
        {
            int akt=0;
            for(int i=0;i<ile;i++)
            {
                int kolumna=idx[i];
                //cout<<"XD"<<kolumna<<endl;
                int pos=j;
                if(i==0) pos+=s1;
                if(i==1) pos+=s2;
                if(i==2) pos+=s3;
                if(i==3) pos+=s4;
                if(pos>pom) pos-=pom;
                akt=max(akt,tab[pos][kolumna]);
            }
            for(int i=1;i<=m;i++)
            {
                if(czy[i]==false) akt=max(akt,tab[j][i]);
            }
            pot+=akt;
            //if(pot==40)
            //{
            //    cout<<s1<<" "<<s2<<" "<<s3<<" "<<s4<<endl;
            //}
        }
        res=max(res,pot);
    }
    cout<<res<<"\n";
}
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin>>t;
    while(t--)
    {
        cin>>n>>m;
        ROZMIAR=n;
        for(int i=0;i<111;i++) czy[i]=false;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++) tab[i][j]=0;
        }
        //cout<<"XD"<<endl;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                int x; cin>>x;
                tab[i][j]=x;
            }
        }
        vector<int> xd;
        for(int i=1;i<=m;i++) xd.push_back(i);
        //cout<<xd.size()<<endl;
        sort(xd.begin(),xd.end(),por);
        //cout<<"KAPPA"<<endl;
        vector<int> idx;
        for(int i=0;i<min(n,(int)xd.size());i++)
        {
            idx.push_back(xd[i]);
            czy[xd[i]]=true;
        }
        solve(idx,n);
    }
 
    return 0;
}