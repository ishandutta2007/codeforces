#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;
typedef long long LL;

LL p, d, ans, ten, q;

int main(){
  cin>>p>>d;
  ans=p;
  ten=1;
  q=p;
 
  for (;;ten*=10) {
    LL x=q/ten%10;
    if (x!=9) q-=(x+1)*ten;

    if (p-d<=q) ans=q;
    else break;
  }
  cout<<ans<<endl;
  return 0;
}