#include <bits/stdc++.h>
typedef long long int ll;
#define mod 1000000007
#define pb push_back
#define mp make_pair
#define vi vector<int>
#define pair pair<int,int>
#define F first
#define S second
#define mem(x) memset(x,0,sizeof(x))

using namespace std;

struct Soldier{
   ll index;
   ll power;
   ll coins;
   ll max_coins=0;
};
typedef struct Soldier knight;

bool waytosort(knight one, knight two)
{
   return one.power<two.power;
}
bool waytosort2(knight one, knight two)
{
   return one.index<two.index;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n,k;
    cin>>n>>k;

    knight arr[n];
    for(ll i=0;i<n;i++)
    {
      arr[i].index = i;
      cin>>arr[i].power;
    }
    for(ll i=0;i<n;i++)
    {
      cin>>arr[i].coins;
    }
    if(k==0)
    {
        for(int i=0;i<n;i++)
        {
            cout<<arr[i].coins<<" ";
        }
        return 0;
    }
    sort(arr,arr+n,waytosort);
    arr[0].max_coins = arr[0].coins;
    for(ll i=1;i<=k;i++)
    {
      arr[i].max_coins = arr[i-1].max_coins + arr[i].coins;
    }

    ll max[k];
    for(ll i=0;i<k;i++)
    {
      max[i] = arr[i].coins;
    }
    sort(max,max + k);
    ll sum = arr[k-1].max_coins;

    for(ll i=k+1;i<n;i++)
    {
      if(arr[i-1].coins > max[0])
      {
         sum-=max[0];
         sum+=arr[i-1].coins;
         max[0] = arr[i-1].coins;
         sort(max, max+k);
      }
      arr[i].max_coins = sum + arr[i].coins;
    }

    sort(arr,arr+n,waytosort2);
    for(int i=0;i<n;i++)
    {
      cout<<arr[i].max_coins<<" ";
    }
    return 0;
}