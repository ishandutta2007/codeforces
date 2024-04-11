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

    int n;
    cin>>n;
    ll arr[n];
    ForA1(n)
      cin>>arr[i];
    sort(arr,arr+n);

    ll p2[31];
	 for(int i=0; i<31; i++)
	 {
	     p2[i]=pow(2,i);
	 }
    int answer =1;
    ll printer[2];
    for(int i=0;i<31;i++)
    {
      ll po = p2[i];
      ForA2(n)
      {
         int first = arr[j];
         bool issecond = binary_search(arr,arr+n,po+first);
         if(issecond)
         {
            bool isthird = binary_search(arr,arr+n,po+first+po);
            if(isthird)
            {
               cout<<"3"<<endl;
               cout<<first<<" "<<first+po<<" "<<first+po+po<<endl;
               return 0;
            }
            else
            {
               if(answer==1)
               {
                  answer =2;
                  printer[0] = first;
                  printer[1] = first+po;
               }
            }
         }
      }
    }

    if(answer==2)
    {
      cout<<"2"<<endl;
      cout<<printer[0]<<" "<<printer[1]<<endl;
    }

    else
    {
      cout<<"1"<<endl;
      cout<<arr[0]<<endl;
   }

    return 0;
}