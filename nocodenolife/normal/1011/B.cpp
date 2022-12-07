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

    int n,m;
    cin>>n>>m;

    map<int,int> food;
    ForA1(m)
    {
      int k;
      cin>>k;
      food[k]++;
    }

    if(m<n)
    {
      cout<<"0"<<endl;
      return 0;
    }
    int max = m/n;
    int answer = max;
    int count = 0;

    while(answer>0)
    {
      count=0;
      for(int i=1;i<=100;i++)
      {
         count += food[i]/answer;
      }
      if(count>=n)
         break;
      answer--;
    }
    cout<<answer<<endl;



    return 0;
}