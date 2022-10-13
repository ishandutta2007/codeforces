#include<stdio.h>

long long mod;

void matpow(long long a[5][5],long long k){
  long long i,j,r[5][5],mem[5][5],t;
  for(i=0;i<5;i++){
    for(j=0;j<5;j++){
      if(i==j){r[i][j]=1;}
      else{r[i][j]=0;}
    }
  }
  while(k>0){
    if(k%2==1){
      for(i=0;i<5;i++){
        for(j=0;j<5;j++){
          mem[i][j]=0;
          for(t=0;t<5;t++){
            mem[i][j]+=r[i][t]*a[t][j];
            mem[i][j]%=mod;
          }
        }
      }
      for(i=0;i<5;i++){
        for(j=0;j<5;j++){
          r[i][j]=mem[i][j];
        }
      }
    }
    k/=2;
    for(i=0;i<5;i++){
      for(j=0;j<5;j++){
        mem[i][j]=0;
        for(t=0;t<5;t++){
          mem[i][j]+=a[i][t]*a[t][j];
          mem[i][j]%=mod;
        }
      }
    }
    for(i=0;i<5;i++){
      for(j=0;j<5;j++){
        a[i][j]=mem[i][j];
      }
    }
  }
  for(i=0;i<5;i++){
    for(j=0;j<5;j++){
      a[i][j]=r[i][j];
    }
  }
}

long long power(long long a, long long b){
	long long x = 1, y = a;
	while (b > 0){
		if(b%2){
			x = (x*y)%mod;
		}
		y = (y*y)%mod;
		b /= 2;
	}
	return x%mod;
}

int main(){
  long long i,j,n,a,b,c,t,r=1;
  long long mat[5][5];
  scanf("%lld%lld%lld%lld%lld",&n,&a,&b,&c,&t);
  mat[0][0]=0;mat[0][1]=1;mat[0][2]=0;mat[0][3]=0;mat[0][4]=0;
  mat[1][0]=0;mat[1][1]=0;mat[1][2]=1;mat[1][3]=0;mat[1][4]=0;
  mat[2][0]=1;mat[2][1]=1;mat[2][2]=1;mat[2][3]=0;mat[2][4]=0;
  mat[3][0]=0;mat[3][1]=0;mat[3][2]=0;mat[3][3]=0;mat[3][4]=0;
  mat[4][0]=0;mat[4][1]=0;mat[4][2]=0;mat[4][3]=0;mat[4][4]=0;
  mod=1000000006;
  matpow(mat,n-3);
  mod=1000000007;
  //for(i=0;i<3;i++){
  //  for(j=0;j<3;j++){
  //    printf("%lld ",mat[i][j]);
  //  }printf("\n");
  //}
  r*=power(a,mat[2][0]);r%=mod;
  r*=power(b,mat[2][1]);r%=mod;
  r*=power(c,mat[2][2]);r%=mod;
  mat[0][0]=0;mat[0][1]=1;mat[0][2]=0;mat[0][3]=0;mat[0][4]=0;
  mat[1][0]=0;mat[1][1]=0;mat[1][2]=1;mat[1][3]=0;mat[1][4]=0;
  mat[2][0]=1;mat[2][1]=1;mat[2][2]=1;mat[2][3]=1;mat[2][4]=0;
  mat[3][0]=0;mat[3][1]=0;mat[3][2]=0;mat[3][3]=1;mat[3][4]=2;
  mat[4][0]=0;mat[4][1]=0;mat[4][2]=0;mat[4][3]=0;mat[4][4]=1;
  mod=1000000006;
  matpow(mat,n-3);
  mod=1000000007;
  r*=power(t,2*mat[2][3]+mat[2][4]);r%=mod;
  //printf("%lld\n",2*mat[2][3]+mat[2][4]);
  printf("%lld\n",r);
}