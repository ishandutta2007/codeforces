#include <iostream>
using namespace std;
typedef long long ll;
int main()
{
ll n,m,k;
cin>>n>>m>>k;
ll x=(n+k-1)/k;
ll y=(m+k-1)/k;
cout<<x*y;
return 0;
}