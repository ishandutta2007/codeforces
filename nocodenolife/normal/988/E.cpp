#include <bits/stdc++.h>

typedef unsigned long long int ull;
typedef long double ldb;
typedef long long int ll;

#define ForA1(n)  for (ll i=0; i<n; i++)
#define ForA2(n)  for (ll j=0; j<n; j++)
#define ForA3(n)  for (ll k=0; k<n; k++)

#define ForN2(n)  for (ll j=1; j<=n; j++)
#define ForN3(n)  for (ll k=1; k<=n; k++)

#define ForN1(n)  for(ll i=1; i<n; i++)

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

    string a;
    cin>>a;
    int n = a.length();
    int pos5=-1;
    int pos2 =-1;
    int pos7 = -1;
    int pos0b = -1;
    int pos0a = -1;
    int consec =0;
    for(int i=0;i<n;i++)
    {
      if(a[i]=='5')
         pos5 = i;
      else if(a[i]=='2')
         pos2 = i;
      else if(a[i]=='7')
         pos7 = i;
      else if(a[i]=='0')
      {
         pos0b = pos0a;
         pos0a = i;
      }
    }
    for(int i=1;i<n;i++)
    {
      if(a[i]=='0')
      {
         consec++;

      }
      else
         break;
    }

    int answer75 = INT_MAX;
    int answer00 = INT_MAX;
    int answer50 = INT_MAX;

    if(pos0a!=-1 && pos0b!=-1)
    {
      answer00 = n-1 - pos0a;
      answer00+= n-2 - pos0b;
    }

    if(pos0a!=-1 && pos5!=-1)
    {
      if(pos5>pos0a)
      {
         answer50 = n-1 - pos0a;
         answer50+= n-2 - pos5;
         answer50+=1;
      }
      else
      {
         if(pos0b<pos5)
         {
            answer50 = n-1 - pos0a;
            answer50+= n-2 - pos5;
         }
      }
    }

    pos7 = pos7>pos2?pos7:pos2;

    if(pos7!=-1 && pos5!=-1)
    {
      if(pos7>pos0a)
      {
         if(pos0a==-1)
         {
            if(pos7>pos5)
            {
               answer75 = n-1 - pos5;
               answer75+= n-2 - pos7;
               answer75 +=1;
            }
            else
            {
               answer75 = n-1 - pos5;
               answer75+= n-2 - pos7;
            }
         }
         else
         {
            if(pos7>pos5)
            {
               answer75 = n-1 - pos5;
               answer75+= n-2 - pos7;
               answer75 +=1;
               if(pos5==0)
                  answer75+=consec;
            }
            else
            {
               answer75 = n-1 - pos5;
               answer75+= n-2 - pos7;
            }
         }
      }
    }
    int answer = answer75;
    answer = answer>answer00?answer00:answer;
    answer = answer>answer50?answer50:answer;

    if(answer == INT_MAX)
    {
      cout<<"-1"<<endl;
    }
    else
    {
      cout<<answer<<endl;
    }
    return 0;
}