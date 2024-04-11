//https://judge.yosupo.jp/submission/39923

#pragma GCC optimize("Ofast", "unroll-loops")
#pragma GCC target("avx2")

#include <bits/stdc++.h>

using namespace std;

namespace fastio {

const int buf_size = 1 << 14;
char buf_read[buf_size];
char buf_write[buf_size + 30];
char *ptr_read = buf_read + buf_size;
char *ptr_write = buf_write;

long long read_int() {
    auto getChar = []() {
        if (ptr_read == buf_read + buf_size){
            fread(buf_read, 1, buf_size, stdin);
            ptr_read = buf_read;
        }
        return *ptr_read++;
    };
    char c = getChar();
    while (c && (c < '0' || c > '9') && c != '-') {
        c = getChar();
    }
    long long z = 1;
    if (c == '-') {
        z = -1;
        c = getChar();
    }
    long long res = 0;
    while (c >= '0' && c <= '9'){
        res = res * 10 + (c - '0');
        c = getChar();
    }
    return z * res;
}

void write_flush() {
    fwrite(buf_write, 1, ptr_write - buf_write, stdout);
    ptr_write = buf_write;
}

void write_int(long long x) {
    if (x < 0) {
        *ptr_write++ = '-';
        x = -x;
    }
    char *start = ptr_write;
    if (!x) {
        *ptr_write++ = '0';
    }
    while (x) {
        *ptr_write++ = x % 10 + '0';
        x /= 10;
    }
    reverse(start, ptr_write);
    if (ptr_write >= buf_write + buf_size) {
        write_flush();
    }
}

void write_char(char c) {
    *ptr_write++ = c;
    if (ptr_write >= buf_write + buf_size) {
        write_flush();
    }
}

}

const int max_n = 1 << 23, mod = 31607;

inline void inc(int &x, int y) {
    x += y;
    if (x >= mod) {
        x -= mod;
    }
}

inline void dec(int &x, int y) {
    x -= y;
    if (x < 0) {
        x += mod;
    }
}

int mul(int x, int y) {
    return 1LL * x * y % mod;
}

template<bool inv>
void and_convolution(int n, int a[]) {
    if (n == 0) {
        return;
    }
    for (int i = 0; i < n / 2; ++i) {
        if (inv) {
            dec(a[i], a[i + n / 2]);
        } else {
            inc(a[i], a[i + n / 2]);
        }
    }
    and_convolution<inv>(n / 2, a);
    and_convolution<inv>(n / 2, a + n / 2);
}

int power(int a,int b){
  int x=1,y=a;
  while(b>0){
    if(b&1ll){
      x=(x*y)%mod;
    }
    y=(y*y)%mod;
    b>>=1;
  }
  return x%mod;
}
int modular_inverse(int n){
  return power(n,mod-2);
}

int n, a[max_n]={0}, b[max_n];
int cl;

void construct(int cf,int cv,int cp,vector<int> &cmat){
  //cerr << cf << ' ' << cv << ' ' << cp << '\n';
  if(cp==n){b[cf]=cv;return;}
  construct(cf,mul(cv,cmat[cp]),cp+1,cmat);
  int nf=cf;
  nf^=(1<<cp);
  if(cp==cl){nf^=(1<<n);}
  if(cp==n-cl-1){nf^=(1<<(n+1));}
  construct(nf,mul(cv,mod+1-cmat[cp]),cp+1,cmat);
}

int main(){
    n=fastio::read_int();
    vector<vector<int>> mat(32,vector<int>(32));
    int ce=modular_inverse(10000);
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
        mat[i][j]=fastio::read_int();
        mat[i][j]*=ce;mat[i][j]%=mod;
      }
    }

    a[(1<<(n+2))-1]=1;
    and_convolution<false>(1 << (n+2), a);
    for(int i=0;i<n;i++){
      cl=i;
      for(int j=0;j<(1<<(n+2));j++){b[j]=0;}
      construct((1<<(n+2))-1,1,0,mat[i]);
      //for(int j=0;j<(1<<(n+2));j++){cerr << b[j] << ' ';}cerr << '\n';
      b[(1<<(n+2))-1]=0;
      and_convolution<false>(1 << (n+2), b);
      for(int j=0;j<(1<<(n+2));j++){
        a[j]=mul(a[j],b[j]);
      }
    }
    and_convolution<true>(1 << (n+2), a);
    //for(int i=0;i<(1<<n+2);i++){cerr << a[i] << '\n';}
    int res=(mod+1-a[0])%mod;
    fastio::write_int(res);
    fastio::write_flush();
    return 0;
}