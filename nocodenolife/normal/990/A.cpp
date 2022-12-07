#include <bits/stdc++.h>
using namespace std;

long long int min(long long int v, long long int w)
{
   if(v>w)
      return w;
   return v;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long int n,m,a,b;
    cin>>n>>m>>a>>b;

    long long int answer = min((n%m)*b, (m-(n%m))*a);

    cout<<answer<<endl;


    return 0;
}