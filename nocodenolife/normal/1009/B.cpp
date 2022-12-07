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

    string s;
    cin>>s;

    int count_1 = 0, count_0=0, count_2 =0;

    for(int i=0;i<s.length();i++)
    {
      if(s[i]=='1')
         count_1++;
      else if(s[i]=='2')
         count_2++;
    }
    if(count_2==0)
    {
      count_0 = s.length() - count_1;
      for(int i=0;i<count_0;i++)
         cout<<"0";
      for(int i=0;i<count_1;i++)
         cout<<"1";
      cout<<endl;
      return 0;
    }
    int first = 0;
    for(int i=0;i<s.length();i++)
    {
      if(s[i]=='2')
      {
         first = i;
         break;
      }
    }

    for(int i=0;i<first;i++)
    {
      if(s[i]=='0')
         cout<<'0';
    }
    for(int i=0;i<count_1;i++)
      cout<<"1";
    for(int i=first;i<s.length();i++)
    {
      if(s[i]!='1')
         cout<<s[i];
    }

    cout<<endl;

    return 0;
}