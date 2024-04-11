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

typedef struct _voter
{
    ll party;
    ll cost;
    ll used;
}voter;

bool waytosort(voter a, voter b)
{
    return a.cost < b.cost;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n,m;
    cin>>n>>m;
    ll votes[m+1] = {0};
    voter arr[n];
    ll counter =0;
    ForA1(n)
    {
        ll part,costs;
        cin>>part>>costs;
        votes[part] ++;
        if(part==1)
        {
            continue;
        }
        arr[counter].party = part;
        arr[counter].cost = costs;
        arr[counter].used = 0;
        counter++;
    }
    n = counter;
    sort(arr,arr+n,waytosort);

    ll reach = 0;
    for(ll i=2;i<=m;i++)
    {
        if(votes[i]>reach)
        {
            reach = votes[i];
        }
    }

    ll answer =0;
    if(votes[1]>reach)
    {
        cout<<"0"<<endl;
        return 0;
    }

    ll req = reach - votes[1] +1;
    for(ll i=0;i<req;i++)
    {
        answer+= arr[i].cost;
    }

    while(reach>0)
    {
        ll ans = 0;
        ll current = votes[1];

        if(current>reach)
        {
            cout<<answer<<endl;
            return 0;
        }

        for(ll i=0;i<n;i++)
        {
            arr[i].used =0;
        }

        for(ll i=2;i<=m;i++)
        {
            if(reach>votes[i])
                continue;
            req = votes[i] - reach +1;
            ll j = 0;
            while(req>0)
            {
                if(arr[j].party==i)
                {
                    ans+= arr[j].cost;
                    arr[j].used = 1;
                    req--;
                    current ++;
                }
                j++;
            }   
        }
        if(current<reach)
        {
            req = reach - current;
            ll j = 0;
            while(req>0)
            {
                if(arr[j].used==0)
                {
                    ans+= arr[j].cost;
                    arr[j].used = 1;
                    req--;
                    current ++;
                }
                j++;
            }   
        }
        else{
            answer = ans>answer?answer:ans;
            cout<<answer<<endl;
            return 0;
        }
        if(ans<answer)
        {
            answer = ans;
        }
        reach --;
    }

    cout<<answer<<endl;

    return 0;
}