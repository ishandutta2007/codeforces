#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;

typedef long long LL;
int n;
LL m;


int main(){

  LL ans=0;
  //scanf("%d%d", &n, &m);
  cin>>n>>m;
  for (int i=0; i<n; i++) {
    LL t, T, x, c;
    LL bus=0, cost;
    LL cm=0;
    //scanf("%d%d%d%d", &t, &T, &x, &c);
    cin>>t>>T>>x>>c;
    cost=c;
    if (t>=T) {
      bus=1;
      cm=(LL)x*(LL)m;
    } else  if (t+m<=T) {
      bus=1;
      cm=0;
    } else {
      LL d, z;
      d=(T-t);
      LL c1, c2;
      z=(m+d-1)/d;
      c1=z*cost;
      bus=z; cm=0;
      if (z>2) {
	z--;
	c2=z*cost+max(m-(z-1)*d,0LL)*x;
	if (c1>c2) {
	  bus=z;
	  cm=max(m-(z-1)*d,0LL)*x;
	  c1=c2;
	}
      }
      if (c1>cost+(LL)m*(LL)x) {
	bus=1;
	cm=(LL)m*(LL)x;
      }
    }
    //cout<<bus<<' '<<cm<<endl;
    ans+=bus*cost+cm;
  }
  
  cout<<ans<<endl;
  return 0;
}