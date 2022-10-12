#include<bits/stdc++.h>
#define mod 1000000007

using namespace std;
using Mat=vector<vector<long long>>;

void matdef(Mat &a,int n){
  a.resize(n);
  for(int i=0;i<n;i++){
    a[i].resize(n);
  }
}

void matI(Mat &a,int n){
  matdef(a,n);
  for(int i=0;i<n;i++){a[i][i]=1;}
}

Mat matmult(Mat a,Mat b,int n){
  Mat res;
  matdef(res,n);
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      for(int k=0;k<n;k++){
        res[i][k]+=a[i][j]*b[j][k];
        res[i][k]%=mod;
      }
    }
  }
  return res;
}

Mat matpow(Mat a,long long k,int n){
  Mat res;
  matI(res,n);
  while(k>0){
    if(k&1){res=matmult(res,a,n);}
    k>>=1;
    a=matmult(a,a,n);
  }
  return res;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  long long k;
  cin >> n >> k;
  vector<long long> vec(16,0);
  vec[0]=1;

  for(int i=0;i<n;i++){
    long long a,b,c;
    cin >> a >> b >> c;
    b=min(k,b);
    Mat cm;
    matdef(cm,16);
    for(int i=0;i<=c;i++){
      for(int j=-1;j<=1;j++){
        if((i+j)<0 || (i+j)>c){continue;}
        cm[i][i+j]=1;
      }
    }
    vector<long long> nv(16,0);
    cm=matpow(cm,b-a,16);
    for(int p=0;p<16;p++){
      for(int q=0;q<16;q++){
        nv[q]+=vec[p]*cm[p][q];
        nv[q]%=mod;
      }
    }
    vec.swap(nv);
  }
  cout << vec[0] << '\n';
  return 0;
}