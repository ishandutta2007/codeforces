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
   int sum;
   int removed;
};
typedef struct Pa pairs;

bool waytosort(pairs a, pairs b)
{
   return a.sum < b.sum;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int number;
    cin>>number;
    pairs arr[400005];
    ll size = 0;
    ForA1(number)
    {
      int ni;
      cin>>ni;
      int array[ni];
      pairs summer[ni];
      int s =0;
      ForA2(ni)
      {
         cin>>array[j];
         s+=array[j];
      }
      ForA2(ni)
      {
         summer[j].index = i+1;
         summer[j].sum = s-array[j];
         summer[j].removed = j+1;
      }
      sort(summer,summer+ni,waytosort);
      arr[size].index = summer[0].index;
      arr[size].sum = summer[0].sum;
      arr[size].removed = summer[0].removed;
      size++;
      ForN2(ni-1)
      {
         if(size == 400005)
            break;
         if(summer[j].sum != summer[j-1].sum)
         {
            arr[size].index = summer[j].index;
            arr[size].sum = summer[j].sum;
            arr[size].removed = summer[j].removed;
            size++;
         }
      }


    }
    sort(arr,arr+size,waytosort);

    ForN1(size-1)
    {
      if(arr[i].sum == arr[i-1].sum && arr[i].index != arr[i-1].index)
      {
         cout<<"YES"<<endl;
         cout<<arr[i].index<<" "<<arr[i].removed<<endl;
         cout<<arr[i-1].index<<" "<<arr[i-1].removed<<endl;
         return 0;
      }
    }

   cout<<"NO"<<endl;
    return 0;
}