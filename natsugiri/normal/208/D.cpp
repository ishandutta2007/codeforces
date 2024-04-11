#include<cstdio>
#include<iostream>


using namespace std;


typedef long long LL;
int n;
LL p[55], c[5], a[5], t;

int main(){

  scanf("%d", &n);
  for (int i=0; i<n; i++) cin>>p[i];
  for (int i=0; i<5; i++) cin>>a[i];
  for (int i=0; i<n; i++) {
    t+=p[i];
    for (int j=4; j>=0; j--) {
      LL x=t/a[j];
      c[j]+=x;
      t-=a[j]*x;
    }
  }
  for (int i=0; i<5; i++) cout<<c[i]<<(i==4?'\n':' ');
  cout<<t<<endl;

  return 0;
}