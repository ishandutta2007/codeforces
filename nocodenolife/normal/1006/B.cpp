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

    int n,k;
    cin>>n>>k;
    int arr[n];
    int sorted[n];

    map<int, int> maximum;
    ll answer = 0;
    ll counter = 0;
    ForA1(n)
    {
      cin>>arr[i];
      sorted[i] = arr[i];
    }
    sort(sorted,sorted+n);

    while(counter !=k)
    {
      maximum[sorted[n-counter-1]]++;
      answer += sorted[n-counter-1];
      counter++;
    }
    cout<<answer<<endl;

    counter = 0;
    int sum = 0;
    int printed = 0;
    for(int i=0;i<n;i++)
    {
      counter++;
      if(printed==k-1)
         break;
      if(maximum[arr[i]]>0)
      {
         cout<<counter<<" ";
         sum+=counter;
         counter = 0;
         maximum[arr[i]]--;
         printed ++;
      }
    }
    if(sum!=n)
    {
      cout<<n-sum<<" ";
    }
    cout<<endl;
    return 0;
}