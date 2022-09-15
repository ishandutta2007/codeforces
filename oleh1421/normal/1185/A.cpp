#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main()
{
   int a,b,c,d;cin>>a>>b>>c>>d;
   if (a>b) swap(a,b);
   if (b>c) swap(b,c);
   if (a>b) swap(a,b);
   int res=max(a-b+d,0)+max(b+d-c,0);
   cout<<res;
   return 0;
}