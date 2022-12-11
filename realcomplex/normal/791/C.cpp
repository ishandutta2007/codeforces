#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double ld;
typedef pair<ll,int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ab(x) ((x) < 0 ? -(x) : (x))
#define all(x) ((x).begin(),(x).end())
#define len(x) ((int)(x).size())

const int R = 1;
const int N = 55;
const int L = (int)1e7 + 9;

string rez[N];

string gen(int x){
  x += L;
  string rez;
  char cur;
  int P = 1;
  while( x >= P){
    cur = (char)((((x * R) % (P * 26)) / P) + 97);
    rez += cur;
    P *= 26;
  }
  rez[0]-=32;
  return rez;
}

int main(){
  fastIO;
  int n,k;
  cin >> n >> k;
  string c;
  int p = k;
  for(int i = 1;i<=n-k+1;i++){
    cin >> c;
    if(c == "NO") {
      if(rez[i].empty())rez[i] = gen(i * 921 + 912);
      rez[p] = rez[i];
    }
    p++;
  }
  for(int i = 1;i<=n;i++)
    if(rez[i].empty())rez[i]=gen(i);
  for(int i = 1;i<=n;i++)cout << rez[i] << " ";
  return 0;
}