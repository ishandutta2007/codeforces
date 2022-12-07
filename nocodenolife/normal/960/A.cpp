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

    string n;
    cin>>n;
    int len = n.length();
    int count_a = 0, count_b=0, count_c=0;
    for(int i=0;i<len;i++)
    {
      if(n[i]=='a')
         count_a++;
      else
         break;
    }
    for(int i=count_a;i<len;i++)
    {
      if(n[i]=='b')
         count_b++;
      else
         break;
    }
    if(count_a==0 || count_b==0)
    {
      cout<<"NO";
      return 0;
    }

    for(int i=(count_b+count_a);i<len;i++)
    {
      if(n[i]=='c')
         count_c++;
      else
         break;
    }
    if(count_a+count_b+count_c!=len)
    {
      cout<<"NO";
      return 0;
    }
    if(count_a==count_c || count_b==count_c)
    {
      cout<<"YES";
      return 0;
    }


    cout<<"NO";
    return 0;
}