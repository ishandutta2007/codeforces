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

    ll l,r,x,y;
    cin>>l>>r>>x>>y;
    ll min = (l+x-1)/x;
    ll max = r/x;
    if(max<min)
    {
        cout<<"0"<<endl;
        return 0;
    }
    if(y%x!=0)
    {
      cout<<"0"<<endl;
      return 0;
    }
    ll divide = y/x;
    ll answer=0;
    if(divide==1)
    {
      if(min==1)
         cout<<"1"<<endl;
      else
         cout<<"0"<<endl;
      return 0;
    }
    if(1==min && max>=divide)
    {
      answer+=2;
    }

    for(int i=2;i<=sqrt(divide);i++)
    {
      if(divide%i==0)
      {
         ll first = i;
         ll second = divide/i;
         if(__gcd(second,first)!=1)
            continue;
         if(first>=min && second<=max)
         {
            answer+=2;
         }
      }
    }
    cout<<answer<<endl;
    return 0;
}