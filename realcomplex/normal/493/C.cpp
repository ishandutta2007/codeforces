#include <bits/stdc++.h>

using namespace std;

int main(){
  int n;
  scanf("%d",&n);
  int tf[n];
  int k1 = n*3;
  for(int i = 0;i<n;i++)
    scanf("%d",&tf[i]);
  int m;
  scanf("%d",&m);
  int k2 = m*3;
  int sf[m];
  for(int i = 0;i<m;i++){
    scanf("%d",&sf[i]);
  }
  sort(tf,tf+n);
  sort(sf,sf+m);
  int l = k1,r = k2;
  int v=0;
  int c;
  for(int i = 0;i<=n;i++){
    if(i!=n)v=tf[i];
    else v=(int)2e9 + 9;
    k2=m*2;
    c=lower_bound(sf,sf+m,v)-sf;
    k2+=m-c;
    //cout << k1 << " " << k2 << "\n";
    if(l-r<k1-k2 or (l-r==k1-k2 and k1>l))
      l=k1,r=k2;
    k1--;
  }
  printf("%d:%d\n",l,r);
  return 0;
}