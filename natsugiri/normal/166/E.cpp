#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

typedef long long LL;
typedef vector<LL> ARY;
typedef vector<ARY> MAT;

#define MOD 1000000007

MAT I(4,ARY(4,0));
int n;

MAT mulModMat(MAT x,MAT y){
  MAT r(4,ARY(4,0));
  for(int j=0;j<4;j++)
    for(int i=0;i<4;i++)
      for(int k=0;k<4;k++)
	r[j][i]=(r[j][i]+x[j][k]*y[k][i])%MOD;

  return r;
}
 
MAT powModMat(MAT x,LL y){
  if(y==0)return I;
  if(y%2)return mulModMat(x,powModMat(x,y-1));
  return powModMat(mulModMat(x,x),y/2);
}



int main(){
  scanf("%d",&n);
  for(int i=0;i<4;i++)I[i][i]=1;
  MAT a(4,ARY(4,1));
  for(int i=0;i<4;i++)a[i][i]=0;
  a=powModMat(a,n);

  printf("%lld\n",a[3][3]%MOD);
  return 0;
}