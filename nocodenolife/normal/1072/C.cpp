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

ll find_max(ll val, ll maxi, ll mini)
{
    if(maxi-mini==0)
    {
        return maxi;
    }
    else if(maxi - mini==1)
    {
        if((maxi*(maxi+1))/2 <= val)
            return maxi;
        return mini;
    }
    ll mid = (maxi+mini)/2;

    if((mid*(mid+1))/2 ==val)
        return mid;
    else if((mid*(mid+1))/2 <val)
        return find_max(val,maxi,mid);
    else
        return find_max(val,mid-1, mini);

}

ll find_max_diff(ll val, ll maxi, ll mini, ll diff)
{
    if(maxi-mini==0)
    {
        return maxi;
    }
    else if(maxi - mini==1)
    {
        if((maxi*(maxi+1))/2 - diff <= val)
            return maxi;
        return mini;
    }
    ll mid = (maxi+mini)/2;

    if((mid*(mid+1))/2 - diff==val)
        return mid;
    else if((mid*(mid+1))/2 - diff <val)
        return find_max_diff(val,maxi,mid,diff);
    else
        return find_max_diff(val,mid-1, mini, diff);

}

int main()
{
    ios_base::sync_with_stdio(false);

    cin.tie(NULL);

    ll a,b;
    cin>>a>>b;
    ll used = a+b;
    if(a==0)
    {
        cout<<"0"<<endl;
        ll st = find_max(b,b,0);
        cout<<st<<endl;
        for(ll i=1;i<=st;i++)
        {
            cout<<i<<" ";
        }
        cout<<endl;
        return 0;
    }
    ll st = find_max(a,a,0);
    ll sum = st*(st+1);
    sum/=2;

    ll dif = a - sum;
    ll val = st+1 - dif;

    cout<<st<<endl;
    for(ll i=1;i<=st+1;i++)
    {
        if(i!=val)
            cout<<i<<" ";
    }
    cout<<endl;

    if(b<val)
    {
        cout<<"0"<<endl;
        return 0;
    }

    b-= val;
    sum = (st+2)*(st+1);
    sum/=2;

    ll num = find_max_diff(b,used,0,sum);
    ll no = num - (st+1);
    cout<<no+1<<endl;
    cout<<val<<" ";

    for(ll i=1;i<=no;i++)
    {
        cout<<st+1+i<<" ";
    }
    cout<<endl;


    return 0;
}