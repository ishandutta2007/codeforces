#include<cstdio>
#include<string>
#include<iostream>
#include<cstring>
using namespace std;


typedef long long LL;
const LL MOD=1000000007;


string str;
int len;

int ika(int p,LL r[3][3]){
  int i,j,ii,jj;
  LL g[3][3];

  memset(g,0,sizeof g);

  if(str[p+1]==')'){
    g[0][1]=g[1][0]=g[0][2]=g[2][0]=1;
    p+=2;
  }else{
    LL hh[3][3];
    p=ika(p+1,hh)+1;
    for(j=0;j<3;j++){
      for(i=0;i<3;i++){
	if(j!=1)g[1][0]=(g[1][0]+hh[j][i])%MOD;
	if(i!=1)g[0][1]=(g[0][1]+hh[j][i])%MOD;
	if(j!=2)g[2][0]=(g[2][0]+hh[j][i])%MOD;
	if(i!=2)g[0][2]=(g[0][2]+hh[j][i])%MOD;
      }
    }
  }

  for(;p<len&&str[p]=='(';){
    LL h[3][3];
    memset(h,0,sizeof h);
    if(str[p+1]==')'){//()
      h[0][1]=h[1][0]=h[0][2]=h[2][0]=1;
      p+=2;
    }else{//((..))
      LL hh[3][3];
      p=ika(p+1,hh)+1;
      for(j=0;j<3;j++){
	for(i=0;i<3;i++){
	  if(j!=1)h[1][0]=(h[1][0]+hh[j][i])%MOD;
	  if(i!=1)h[0][1]=(h[0][1]+hh[j][i])%MOD;
	  if(j!=2)h[2][0]=(h[2][0]+hh[j][i])%MOD;
	  if(i!=2)h[0][2]=(h[0][2]+hh[j][i])%MOD;
	}
      }
    }
    LL gg[3][3];
    for(j=0;j<3;j++)for(i=0;i<3;i++)gg[j][i]=g[j][i];    
    memset(g,0,sizeof g);
    for(j=0;j<3;j++){
      for(i=0;i<3;i++){
	for(jj=0;jj<3;jj++){
	  for(ii=0;ii<3;ii++){
	    if(i==jj&&(i==1||i==2))continue;
	    g[j][ii]=(g[j][ii]+h[j][i]*gg[jj][ii]%MOD)%MOD;
	  }
	}
      }
    }
  }
  for(j=0;j<3;j++){
    for(i=0;i<3;i++){
      r[j][i]=g[j][i];
    }
  }
  return p;
}
  
  
int main(){
  int i,j;
  LL g[3][3],ans;

  cin>>str;
  len=str.size();
  ika(0,g);
  ans=0;
  for(j=0;j<3;j++)for(i=0;i<3;i++)ans=(ans+g[j][i])%MOD;
  printf("%lld\n",ans);
  return 0;
}