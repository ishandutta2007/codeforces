#include<stdio.h>

long long llmax(long long a,long long b){if(a>b){return a;}return b;}
long long llmin(long long a,long long b){if(a<b){return a;}return b;}
long long llc2(long long a){if(a%2==0){return a/2;}return ((a+1)/2);}

long long calc(long long tp,long long u,long long d){
  long long st,fi,te;
  long long eu,ed,res=(1ll<<60);
  st=-(1ll<<60);
  fi=(1ll<<60);
  while(st<=fi){
    te=(st+fi)/2;
    ed=te;eu=tp-te;
    eu+=u;
    long long cv=llmax(ed,eu);
    res=llmin(cv,res);
    if(ed>eu){fi=te-1;}
    else{st=te+1;}
  }
  return res;
}

int main(){
  long long n,a[524288],del[524288],us=0,ds=0;
  long long deldel;
  scanf("%lld",&n);
  for(int i=1;i<=n;i++){
    scanf("%lld",&a[i]);
    if(i!=1){
      del[i-1]=(a[i]-a[i-1]);
      //printf("<%lld>\n",del[i]);
      us+=llmax(del[i-1],0);
      ds+=llmax(-del[i-1],0);
    }
  }
  //for(int i=1;i<=n-1;i++){printf("<%lld>",del[i]);}puts("");
  printf("%lld\n",calc(a[1],us,ds));
  long long q;
  scanf("%lld",&q);
  while(q>0){
    q--;
    long long l,r,x;
    scanf("%lld%lld%lld",&l,&r,&x);
    
    if(l!=1){
      us-=llmax(del[l-1],0);
      ds-=llmax(-del[l-1],0);
    }
    if(r!=n){
      us-=llmax(del[r],0);
      ds-=llmax(-del[r],0);
    }
    
    if(l==1){a[1]+=x;}else{del[l-1]+=x;}
    if(r!=n){del[r]-=x;}
    
    if(l!=1){
      us+=llmax(del[l-1],0);
      ds+=llmax(-del[l-1],0);
    }
    if(r!=n){
      us+=llmax(del[r],0);
      ds+=llmax(-del[r],0);
    }

    //for(int i=1;i<=n-1;i++){printf("<%lld>",del[i]);}puts("");

    printf("%lld\n",calc(a[1],us,ds));
  }
  return 0;
}