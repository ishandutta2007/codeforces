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

struct Pa
{
   int index;
   int val;
};
typedef struct Pa pairs;

bool waytosort(pairs a, pairs b)
{
   return a.val < b.val;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,k;
    cin>>n>>k;

    pairs arr[n];
    ForA1(n)
    {
      cin>>arr[i].val;
      arr[i].index = i+1;
    }
    sort(arr,arr+n,waytosort);

    int answer[k] = {arr[0].index};
    int size =1;
    for(int i=1;i<n;i++)
    {
      if(size==k)
         break;
      if(arr[i].val!=arr[i-1].val)
      {
         answer[size] = arr[i].index;
         size++;
      }
    }
    if(size==k)
    {
      cout<<"YES"<<endl;
      for(int i=0;i<k;i++)
      {
         cout<<answer[i]<<" ";
      }
      cout<<endl;
   }
   else
   {
      cout<<"NO"<<endl;
   }


    return 0;
}