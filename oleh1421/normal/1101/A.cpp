#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int main()
{
   int q;cin>>q;
   while (q--){
      ll l,r,d;cin>>l>>r>>d;
      if (l<=d) cout<<(r/d+1)*d<<endl;
      else cout<<d<<endl;
   }
}