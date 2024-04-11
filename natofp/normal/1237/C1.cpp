#include <iostream>
#include <bits/stdc++.h>
#define ll long long int
using namespace std;

struct xd
{
    int a,b,c;
    int idx;
};

vector<xd> jd;

const int nax=2005;
bool taken[nax];

bool por(xd jeden,xd dwa)
{
    if(jeden.a==dwa.a)
    {
        if(jeden.b==dwa.b)
        {
            return jeden.c<dwa.c;
        }
        return jeden.b<dwa.b;
    }
    return jeden.a<dwa.a;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int a,b,c; cin>>a>>b>>c;
        xd nowy;
        nowy.a=a;
        nowy.b=b;
        nowy.c=c;
        nowy.idx=i+1;
        jd.push_back(nowy);
    }
    sort(jd.begin(),jd.end(),por);
    for(int i=0;i<n;i++)
    {
        xd akt=jd[i];
        xd prob;
        int idx=-1;
        if(taken[i]==true) continue;
        for(int j=i+1;j<n;j++)
        {
            if(taken[j]==true) continue;
            prob=jd[j];
            idx=j;
            break;
        }
        for(int j=i+1;j<n;j++)
        {
            if(taken[j]==true) continue;
            xd pot=jd[j];
            if(pot.a>=min(prob.a,akt.a) && pot.a<=max(prob.a,akt.a) && pot.b>=min(prob.b,akt.b) && pot.b<=max(prob.b,akt.b) && pot.c>=min(prob.c,akt.c) && pot.c<=max(prob.c,akt.c))
            {
                prob=pot;
                idx=j;
            }
        }
        taken[i]=true;
        taken[idx]=true;
        cout<<prob.idx<<" "<<akt.idx<<endl;
    }
    return 0;
}