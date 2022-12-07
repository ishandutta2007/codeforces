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

    string str;
    cin>>str;

    for(int i=0;i<str.length();i++)
    {
      if(!((str[i]=='a')||(str[i]=='e')||(str[i]=='i')||(str[i]=='o')||(str[i]=='u')||(str[i]=='n')))
      {
         if(i==str.length()-1)
         {
            cout<<"NO"<<endl;
            return 0;
         }
         else
         {
            if((!((str[i+1]=='a')||(str[i+1]=='e')||(str[i+1]=='i')||(str[i+1]=='o')||(str[i+1]=='u'))))
               {
                  cout<<"NO"<<endl;
                  return 0;
               }
         }
      }
    }
    cout<<"YES"<<endl;

    return 0;
}