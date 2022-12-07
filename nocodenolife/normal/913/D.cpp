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

struct ques
{
   ll time;
   ll max_point;
   ll index;
};
typedef struct ques question;

bool waytosort(question a, question b)
{
   return a.time < b.time;
}

ll check(ll tim, question * arr, ll n,ll mid)
{
   ll left = tim;
   ll taken = 0;
   for(ll i=0;i<n;i++)
   {
      if(arr[i].time<=left)
      {
         if(arr[i].max_point>=mid)
         {
            left-=arr[i].time;
            taken++;
         }
      }
      else
         break;
   }
   return taken;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n,tim;
    std::cin >> n>>tim;
    ll finder[n+1] = {0};
    question arr[n];
    ForA1(n)
    {
      cin>>arr[i].max_point>>arr[i].time;
      arr[i].index = i+1;
      finder[arr[i].max_point]++;
    }
    ll max;
    if(finder[n]==n)
      max = n;
    else
    {
      for(ll i=n-1;i>0;i--)
      {
         finder[i]+= finder[i+1];
         if(finder[i]>=i)
         {
            max = i;
            break;
         }
      }
    }
    sort(arr,arr+n,waytosort);

    ll min = 0;
    while(!(max-min==0 || max-min==1))
    {
      ll mid = (max+min)/2;
      ll taken = check(tim,arr,n,mid);
      if(taken>=mid)
         min = mid;
      else
         max = mid;
    }
    ll taken = check(tim,arr,n,max);
    if(taken< max)
      max = min;

    if(max==0)
    {
      cout<<"0"<<endl<<"0"<<endl;
      return 0;
    }
    cout<<max<<endl;
    cout<<max<<endl;
    ll left = tim;
    taken = max;
    ll i=0;
    while(taken>0)
    {
      if(arr[i].time<=left)
      {
         if(arr[i].max_point>=max)
         {
            left-=arr[i].time;
            taken--;
            cout<<arr[i].index<<" ";
         }
      }
      i++;
    }
    cout<<endl;
    return 0;
}