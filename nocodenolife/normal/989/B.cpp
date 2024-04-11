#include <bits/stdc++.h>
typedef long long int ll;
#define mod 1000000007
#define pb push_back
#define mp make_pair
#define vi vector<int>
#define pair pair<int,int>
#define F first
#define S second
#define mem(x) memset(x,0,sizeof(x))

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,p;
    cin>>n>>p;

    string s;
    cin>>s;
    int answer = 0;
    for(int i=0;i<p;i++)
    {
      int ones =0;
      int zeroes = 0;
      int dots = 0;
      int j=i;
      while(j<n)
      {
         if(s[j]=='1')
            ones++;
         else if(s[j]=='0')
            zeroes++;
         else
            dots++;
         j+=p;
      }
      j=i;
      if(dots>0)
      {
         if(zeroes!=0)
         {
            while(j<n)
            {
               if(s[j]=='.')
                  s[j]='1';
               j+=p;
            }
            answer=1;
         }
         else if(ones!=0)
         {
            while(j<n)
            {
               if(s[j]=='.')
                  s[j]='0';
               j+=p;
            }
            answer=1;
         }
         else
         {
            if(dots>1)
            {
               answer=1;
               char k = '1';
               while(j<n)
               {
                  if(s[j]=='.')
                     s[j]=k;
                  k = '0';
                  j+=p;
               }
            }
         }
      }
      else
      {
         if(zeroes!=0 && ones!=0)
            answer=1;
      }

    }
    if(answer==0)
    {
      cout<<"No"<<endl;
      return 0;
    }
    for(int i=0;i<n;i++)
    {
      if(s[i]=='.')
         s[i]='0';
   }
    cout<<s<<endl;

    return 0;
}