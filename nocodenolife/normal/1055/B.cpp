#include <bits/stdc++.h>

typedef unsigned long long int ull;
typedef long double ldb;
typedef long long int ll;

#define ForA1(n)  for (ll i=0; i<n; i++)
#define ForA2(n)  for (ll j=0; j<n; j++)
#define ForA3(n)  for (ll k=0; k<n; k++)
#define ForN1(n)  for (ll i=1; i<=n; i++)
#define ForN2(n)  for (ll j=1; j<=n; j++)
#define ForN3(n)  for (ll k=1; k<=n; k++)

#define mod 1000000007
#define pb push_back
#define mp make_pair
#define vi vector<int>
#define pair pair<int,int>
#define F first
#define S second
#define mem(x) memset(x,0,sizeof(x))
#define PI 3.1415926535897932384626433832795l
#define deci(n) cout<<fixed<<setprecision(n);


using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n,m,l;
    cin>>n>>m>>l;

    ll q;
    ll p,d;
    ll answer=0;
    ll starti=-1;
    if(n==1)
    {
        ll be;
        cin>>be;

        ForA3(m)
        {
            cin>>q;
            if(q==1)
            {
                cin>>p>>d;
                p--;
                be+=d;
            }
            else
            {
                if(be>l)
                    cout<<"1"<<endl;
                else
                    cout<<"0"<<endl;
            }
        }

        return 0;
    }

    ll len[n];
    ll boole[n];
    ForA1(n)
    {
        cin>>len[i];
        if(len[i]>l)
            boole[i]=1;
        else
            boole[i]=0;
    }
    

    ForA1(n)
    {
        if(boole[i]==1)
        {
            if(starti==-1)
            {
                starti=i;
                answer++;
            }
        }
        else
        {
            starti=-1;
        }
    }
    ForA3(m)
    {
        cin>>q;
        if(q==1)
        {
            cin>>p>>d;
            p--;
            if(boole[p]==1)
            {
                len[p] = len[p] + d;
                continue;
            }
            len[p] = len[p] + d;
            if(len[p]>l)
            {
                boole[p]=1;
                // cout<<"hi";
                if(p==0)
                {
                    if(boole[1]==1)
                        continue;
                    else
                        answer++;
                    continue;
                }
                if(p==n-1)
                {
                    if(boole[n-2]==1)
                        continue;
                    else
                        answer++;
                    continue;
                }
                // cout<<"hi";
                if(boole[p+1]==1)
                {
                    if(boole[p-1]==1)
                    {
                        answer--;
                    }
                    else
                    {
                        continue;
                    }
                }
                else{
                    if(boole[p-1]==1)
                    {
                        continue;
                    }
                    else
                    {
                        answer++;
                    }
                }
            }
            else
            {
                continue;
            }
        }
        else{
            cout<<answer<<endl;
        }

        // for(ll i=0;i<n;i++)
        // {
        //     cout<<boole[i]<<" ";
        // }
        // cout<<endl;
    }

    return 0;
}