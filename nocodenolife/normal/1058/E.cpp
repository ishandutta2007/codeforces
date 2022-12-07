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

    ll n;
    cin>>n;

    ll arr[n];
    ll num;
    ll sum;
    ll answer = 0;
    for(ll i=0;i<n;i++)
    {
        cin>>num;
        sum = 0;
        while(num>0)
        {
            sum += num%2;
            num/=2;
        }
        arr[i] = sum;
    }

    ll even[n];
    ll odd[n];

    if(arr[0]%2==0)
    {
        even[0]=1;
        odd[0] = 0;
    }
    else
    {
        odd[0] = 1;
        even[0] = 0;
    }

    
    for(ll i=1;i<n;i++)
    {
        
        if(arr[i]%2==0)
        {
            even[i] = even[i-1]+1;
            odd[i] = odd[i-1];
        }
        else
        {
            odd[i] = even[i-1]+1;
            even[i] = odd[i-1];
        }
    }
    // for(ll i=0;i<n;i++)
    // {
    //     cout<<arr[i]<<" "<<even[i]<<" "<<odd[i]<<endl;
    // }
    for(ll i=0;i<n;i++)
    {
        ll val = arr[i];
        ll max  = val;
        ll sum = val;
        ll index = i;
        while(max*2>sum && index>0)
        {
            index--;
            sum+=arr[index];
            if(arr[index]>max)
                max = arr[index];
        }

        if(index==0)
        {
            if(max*2<=sum)
            {
                if(sum%2==0)
                {
                    answer++;
                    // cout<<answer<<" "<<i<<" "<<index<<endl;
                }
            }
        }
        else{
            if(sum%2==0)
            {
                answer+=even[index-1]+1;
                // cout<<answer<<" "<<i<<" "<<index<<endl;
            }
            else{
                answer+=odd[index-1];
                // cout<<answer<<" "<<i<<" "<<index<<endl;
            }
            ll toreach = i-70;
            if(toreach<0)
                toreach=0;
            while(index>toreach)
            {
                index--;
                sum+=arr[index];
                if(arr[index]>max)
                    max = arr[index];
                if(max*2>sum && sum%2==0)
                {
                    answer--;
                }
            }
        }
    }
    cout<<answer<<endl;
    return 0;
}