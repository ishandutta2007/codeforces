#include<bits/stdc++.h>
using namespace std;
#define ll long long

bitset<7070>b[101000], ys[7070], bs[7070];
int mu[7070];

int n, q;

int main(){
  {
    int n=7000;
    for (int i=1;i<=n;++i){
      mu[i]= (i==1)-mu[i];
      for (int j=i+i;j<=n;j+=i){
	mu[j]+=mu[i];
      }
    }
    for (int i=1;i<=n;++i)
      for (int j=i;j<=n;j+=i)
	ys[j][i]=1, bs[i][j]= mu[j/i]? 1: 0;
  }
  cin>>n>>q;
  for (int t,x,y,z,v;q--;){
    scanf("%d",&t);
    if (t==1){
      scanf("%d%d",&x,&v);
      b[x]=ys[v];
    }else if (t==2){
      scanf("%d%d%d",&x,&y,&z);
      b[x]=b[y]^b[z];
    }else if (t==3){
      scanf("%d%d%d",&x,&y,&z);
      b[x]=b[y]&b[z];
    }else if (t==4){
      scanf("%d%d",&x,&v);
      putchar((b[x]&bs[v]).count()%2? '1': '0');
    }
  }
  puts("");
}