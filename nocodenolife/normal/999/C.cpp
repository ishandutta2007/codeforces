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
    string s;
    cin>>s;

    if(k>=n)
    {
      cout<<endl;
      return 0;
    }
    int inuse[26] = {0};
    ForA1(n)
    {
      inuse[(int)(s[i]-'a')]++;
    }
    int toremove[26]={0};
    int c=0;
    while(k>0)
    {
      if(inuse[c]>=k)
      {
         toremove[c]=k;
         k=0;
      }
      else
      {
         toremove[c]=inuse[c];
         k-=inuse[c];
         c++;
      }
    }

    ForA1(n)
    {
      if(toremove[(int)(s[i]-'a')]!=0)
      {
         toremove[(int)(s[i]-'a')]--;
      }
      else
      {
         cout<<s[i];
      }
    }
    cout<<endl;
    return 0;
}