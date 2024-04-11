#include<bits/stdc++.h>

using namespace std;

vector<long double> bx={
  3.830127018922193,
  -3.601321235851749,
  0.466045194906253,
  10.411264148588986,
  12.490381056766580
};

vector<long double> by={
  3.366025403784439,
  10.057331467373021,
  19.192786043799030,
  18.147501411122495,
  8.366025403784439
};

int main(){
  int n;
  scanf("%d",&n);
  printf("%d\n",4*n+1);
  long double dx=bx[0]-bx[2];
  long double dy=by[0]-by[2];
  for(int i=0;i<5*n;i++){
    if(5<=i && i%5==2){continue;}
    int ce=(i/5);
    long double lce=ce;
    printf("%.20Lf %.20Lf\n",bx[i%5]+lce*dx,by[i%5]+lce*dy);
  }

  int cur=4*n-2;
  vector<int> res;
  while(1){
    if(cur==2){cur=1;}
    res.push_back(cur);
    if(cur==1){break;}
    cur-=4;
  }

  printf("1 2 3 4 5\n");
  res.push_back(3);
  res.push_back(5);
  res.push_back(2);
  res.push_back(4);
  int pre=1;
  for(int i=1;i<n;i++){
    printf("%d %d %d %d %d\n",4*i+2,4*i+3,pre,4*i+4,4*i+5);
    res.push_back(pre);
    res.push_back(4*i+5);
    res.push_back(4*i+3);
    res.push_back(4*i+4);
    pre=4*i+2;
  }

  if(n!=1){res.push_back(4*n-2);}
  else{res.push_back(1);}

  for(int i=0;i<=5*n;i++){
    if(i){printf(" ");}
    printf("%d",res[i]);
  }printf("\n");
  return 0;
}