#include<cstdio>

const double EPS=1e-12;
int n,l,v1,v2;
double a[300001];

double len[100010];

int main(){
  scanf("%d%d%d%d",&n,&l,&v1,&v2);
  for(int i=0;i<n;i++){
    int x;
    scanf("%d",&x);
    a[i]=x;
    a[i+n]=x+(double)l*2.0;
    a[i+2*n]=x+(double)l*4.0;
  }
  double t=(double)l/(v1+v2);
  double r=l-t*v1;

  int le,ri;
  double pos;
  le=ri=0;
  pos=a[0];
  for(;r>a[ri]-pos;ri++);
  for(;le<n;){
    if(a[le+1]-pos>a[ri]-r-pos){
      len[ri-1-le]+=a[ri]-r-pos;
      pos=a[ri]-r;
      ri++;
    }else{
      len[ri-1-le]+=a[le+1]-pos;
      le++;
      pos=a[le];
    }
  }
  for(int i=0;i<=n;i++)
    printf("%.20f\n",len[i]/2.0/(double)l);
      
  return 0;
}