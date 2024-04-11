#include<cstdio>
#include<algorithm>
#include<vector>
#include<string>
#include<iostream>
using namespace std;

int n;
string A, B;

double x[26][200100], y[26][200100];
  

int main(){

  scanf("%d", &n);
  cin>>A>>B;
  for (int i=0; i<n; i++) {
    int c=A[i]-'A';
    for (int j=0; j<26; j++) {
      x[j][i+1]=x[j][i];
      if (j==c) {
	x[j][i+1]+=i+1;
      }
    }
  }

  for (int i=n-1; i>=0; i--) {
    int c=A[i]-'A';
    for (int j=0; j<26; j++) {
      y[j][i]=y[j][i+1];
      if (j==c) {
	y[j][i]+=n-i;
      }
    }
  }
    
  double ans=0;
  for (int i=0; i<n; i++) {
    int c=B[i]-'A';
    if (i) ans+=x[c][i]*(n-i);
    if (i<n) ans+=(i+1)*y[c][i+1];
    if (A[i]==B[i]) ans+=(double)(i+1.0)*(n-i);
  }
  printf("%.16f\n", ans*6/n/(n+1)/(2*n+1));
  return 0;
}