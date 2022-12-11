#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)1e7 + 10;
int cnt[N];
int phi[N];
int low[N];
int cur[N];

int main(){
  fastIO;
  int n;
  cin >> n;
  phi[1]=0;
  for(int i = 1; i <= n; i ++ ){
    low[i] = i;
    cnt[i]=1;
  }
  for(int i = 2; i <= n; i ++ ){
    if(low[i] == i){
      phi[i] = i - 1;
    }
    else{
      phi[i] = phi[i/low[i]];
      if((i / low[i]) % low[i] == 0)
        phi[i] *= low[i];
      else
        phi[i] *= (low[i]-1);
    }
    for(int j = i ; j <= n ; j += i ){
      if(low[j]==j)low[j]=i;
      cnt[j]++;
    }
  }
  ll one = 0;
  for(int i = 1; i <= n; i ++ ){
    one += (i - 1 - phi[i]);
  }
  ll two = 0;
  for(int i = 2; i <= n; i ++ ){
    cur[low[i]] ++ ;
  }
  for(int i = 2; i <= n; i ++ )
    cur[i] += cur[i - 1];
  int lim;
  for(int i = 2; i <= n; i ++ ){
    lim = n/low[i];
    two += cur[lim];
    if(low[i] * 1ll * low[i] <= n)
      two -- ;
  }
  two -= 2 * one;
  two /= 2;
  ll three = n * 1ll * (n - 1) / 2ll;
  three -= one;
  three -= two;
  ll cnt = 0;
  for(int i = 1; i <= n; i ++ ){
    if(i == 1 || (low[i] == i && i * 2 > n)) cnt ++ ; 
  }
  three -= cnt * 1ll * (n - cnt); // isolated vertices
  three -= cnt * 1ll * (cnt - 1) / 2ll;
  cout << one + two * 2ll + 3ll * three << "\n";
  return 0;
}