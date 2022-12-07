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

    map<char, int> finder;
    for(int i=0;i<n;i++)
    {
      char c;
      cin>>c;
      finder[c]++;
    }

    char prev = ' ';
    char curr = 'a';
    curr--;
    int counter = 0;
    int answer = 0;
    while(counter<k && curr!='z')
    {
      curr++;
      if(finder[curr]>0 && (int)(curr-prev)>1)
      {
         prev = curr;
         answer+= (int)(curr - 'a' +1);
         counter++;
      }
    }
    if(counter!=k)
      answer = -1;
    cout<<answer<<endl;
    return 0;
}