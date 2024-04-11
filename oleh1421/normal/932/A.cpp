#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>
#include <vector>
typedef long long ll;
using namespace std;

bool is_c(ll a){
   ll x=sqrt(a);
   return (x*x==a);
}
int main()
{
   string s,s1;
   cin>>s;
   s1=s;
   reverse(s.begin(),s.end());
   cout<<s1<<s;
   return 0;
}