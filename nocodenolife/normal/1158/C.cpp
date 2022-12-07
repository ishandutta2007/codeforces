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
#define vll vector<ll>
#define F first
#define S second
#define debug(x)    cerr << #x << " = " << x << endl;
#define mem(x) memset(x,0,sizeof(x))
#define PI 3.1415926535897932384626433832795l
#define deci(n) cout<<fixed<<setprecision(n);


using namespace std;

int main()
{
	#ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin);
	    freopen("output.txt", "w", stdout);
	#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll t;
    cin>>t;
    ll n;
    int flag;
    ll maxi;
    ll arr[500005];
    ll check[500005];
    ll ans[500005];
    ForN3(t)
    {
        cin>>n;
        ForN1(n)
            cin>>arr[i];
        
        flag = 0;
        maxi = arr[1];
        vector<ll> brr[n+2];
        ForN1(n)
        {
            maxi = max(maxi,i+1);
            if(arr[i]==-1)
            {
                arr[i] = i+1;
                brr[arr[i]].push_back(i);
                continue;
            }
            if(arr[i]<i+1)
            {
                //cout<<i;
                flag =1;
                break;
            }
            maxi = max(maxi,arr[i]);
            brr[arr[i]].push_back(i);
        }
        if(flag)
        {
            cout<<-1<<endl;
            continue;
        }
        maxi = n;
        for(ll i=n+1;i>=0;i--)
        {
            for(ll j=0;j<brr[i].size();j++)
            {
                ans[brr[i][j]] = maxi;
                maxi--;
            }
        }
        
        check[n] = n+1;
        for(ll i=n-1;i>0;i--)
        {
            maxi = i+1;
            while(maxi<n+1 && ans[maxi]<ans[i])
                maxi = check[maxi];
            check[i]=maxi;
            if(check[i]!=arr[i])
            {
                flag = 1;
                break;
            }
        }
        if(flag)
        {
            cout<<-1<<endl;
            continue;
        }
        ForN1(n)
            cout<<ans[i]<<" ";
        cout<<endl;
    }

    return 0;
}