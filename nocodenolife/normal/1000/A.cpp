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

/*
XXXS = 0
XXS = 1
XS = 2
S = 3
M = 4
L = 5
XL = 6
XXL = 7
XXXL = 8
*/
int mymod(int a)
{
   if(a>0)
      return a;
   return -1*a;
}

int mymax(int a, int b, int c)
{
   a = a>b?a:b;
   a = a>c?a:c;
   return a;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    int prev[9] = {0};
    for(int i=0;i<n;i++)
    {
      string s;
      cin>>s;
      if(s=="XXXS")
         prev[0]++;
      else if(s=="XXS")
         prev[1]++;
      else if(s=="XS")
         prev[2]++;
      else if(s=="S")
         prev[3]++;
      else if(s=="M")
         prev[4]++;
      else if(s=="L")
         prev[5]++;
      else if(s=="XL")
         prev[6]++;
      else if(s=="XXL")
         prev[7]++;
      else
         prev[8]++;
    }

    int next[9] = {0};
    for(int i=0;i<n;i++)
    {
      string s;
      cin>>s;
      if(s=="XXXS")
         next[0]++;
      else if(s=="XXS")
         next[1]++;
      else if(s=="XS")
         next[2]++;
      else if(s=="S")
         next[3]++;
      else if(s=="M")
         next[4]++;
      else if(s=="L")
         next[5]++;
      else if(s=="XL")
         next[6]++;
      else if(s=="XXL")
         next[7]++;
      else
         next[8]++;
    }

    int answer = 0;
    answer += mymod(next[0] - prev[0]);
    answer += mymod(next[1] - prev[1]);
    answer += mymod(next[2] - prev[2]);
    answer+= mymax(mymod(next[3] - prev[3]),mymod(next[4] - prev[4]),mymod(next[5] - prev[5]));
    cout<<answer<<endl;
    return 0;
}