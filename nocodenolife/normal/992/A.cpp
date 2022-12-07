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

    int n;
    cin>>n;
    int arr[n];
    int iszero=0;
    for(int i=0;i<n;i++)
    {
      cin>>arr[i];
      if(arr[i]==0)
         iszero=1;
    }

    sort(arr,arr+n);
    int answer = 1;
    for(int i=1;i<n;i++)
    {
      if(arr[i]!=arr[i-1])
         answer++;
    }
    answer-=iszero;
    cout<<answer<<endl;
    return 0;
}