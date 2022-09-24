#include<cstdio>

int n, a;


bool good(int x, int y){
  if(x==y || x+y==n-1)return 1;
  if(x==n/2 || y==n/2)return 1;
  return 0;
}

int main(){
  int sum=0;
  scanf("%d", &n);
  
  for(int j=0; j<n; j++){
    for(int i=0; i<n; i++){
      scanf("%d", &a);
      if(good(i, j))sum+=a;
    }
  }

  printf("%d\n", sum);

  return 0;
}