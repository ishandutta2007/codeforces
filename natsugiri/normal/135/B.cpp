#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;
int x[8],y[8],p[8];

int sq(int n){
  return n*n;
}

int isRect(int k){

  int vx[4],vy[4];
  int i;
  for(i=0;i<4;i++){
    vx[i]=x[p[k+i]]-x[p[k]];
    vy[i]=y[p[k+i]]-y[p[k]];
  }
  if(vx[1]+vx[3]==vx[2] && vy[1]+vy[3]==vy[2]){
    if(vx[1]*vx[3] + vy[1]*vy[3] == 0){

      if(sq(vx[1])+sq(vy[1]) == sq(vx[3])+sq(vy[3])){
	
	return 2;//square

      }else{
	return 1;//rect
      }
    }
  }
  return 0;
}
 
int main(){
  int n,i;
  for(i=0;i<8;i++){ scanf("%d%d",x+i,y+i); p[i]=i; }
  do{
    if(isRect(0)==2 && isRect(4)>0){
      puts("YES");
      sort(p,p+4);
      sort(p+4,p+8);
      for(i=0;i<4;i++)printf("%s%d",i?" ":"",p[i]+1);
      puts("");
      for(i=0;i<4;i++)printf("%s%d",i?" ":"",p[i+4]+1);
      puts("");
      return 0;
    }
  }while(next_permutation(p,p+8));
  puts("NO");
  return 0;
}