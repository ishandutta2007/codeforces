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

    int n,m;
    cin>>n>>m;
    int keys[n];
    int check[m];
    for(int i=0;i<n;i++)
    {
      cin>>keys[i];
    }
    for(int i=0;i<m;i++)
    {
      cin>>check[i];
    }
    for(int i=0;i<n;i++)
    {
      for(int j=0;j<m;j++)
      {
         if(keys[i]==check[j])
         {
            cout<<keys[i]<<" ";
            break;
         }
      }
    }

    return 0;
}