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

long long int mymodulus(long long int x)
{
   if(x>0)
      return x;
   return -1*x;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long int n, k1,k2,k;
    cin>>n>>k1>>k2;
    k = k1+k2;
    long long int a[n];
    long long int b[n];
    long long int diff[n+1];
    for(int i=0;i<n;i++)
    {
      cin>>a[i];
    }
    long long int sum=0;
    diff[0] = 0;
    for(long long int i=0;i<n;i++)
    {
      cin>>b[i];
      diff[i+1] = mymodulus(a[i]-b[i]);
      sum+=diff[i+1];
    }
    if(sum<=k)
    {
      k-=sum;
      if(k%2==0)
      {
         cout<<"0"<<endl;
         return 0;
      }
      else
      {
         cout<<"1"<<endl;
         return 0;
      }
    }

    sort(diff, diff+n+1);
    long long int num=1;
    long long int dif = diff[n] - diff[n-1];


    while(num*dif < k)
    {
      k-= num*dif;
      for(long long int i=0;i<num;i++)
      {
         diff[n-i]-=dif;
      }
      num++;
      dif = diff[n] - diff[n-num];
    }
    dif = k/num;
    for(long long int i=0;i<num;i++)
    {
      diff[n-i]-=dif;
    }
    k -= num*dif;
    for(long long int i=0;i<k;i++)
    {
      diff[n-i]-=1;
    }

    long long int answer=0;
    for(int i=0;i<=n;i++)
    {
      answer+= diff[i] * diff[i];
    }

    cout<<answer<<endl;

    return 0;
}