#include <bits/stdc++.h>

using namespace std;

const int N = 1000100;

int n, From, To;
int a[N];
int f[N];
int Smallest[N];
map < int, int > Used;

int main(){
  #ifdef pts
    freopen("1.inp", "r", stdin);
  #endif // pts
  scanf("%d", &n);
  for(int i = 1; i <= n; ++i){
    scanf("%d", a + i);
  }
  fill(Smallest + 1, Smallest + N, 1e9);
  scanf("%d%d", &To, &From);
  for(int i = 1; i <= n; ++i){
    if(Used[a[i]] == 1){
      continue;
    }
    Used[a[i]] = 1;
    int Last = From;
    if(Last % a[i] != 0){
      Last += a[i] - Last % a[i];
    }
    while(Last <= To){
      int Fuck = Last + a[i] - 1;
      if(Fuck > To){
        Smallest[To - From] = min(Smallest[To - From], Last - From);
        break;
      }
      Smallest[Fuck - From] = min(Smallest[Fuck - From], Last - From);
      Last += a[i];
    }
  }
  for(int i = To - From; i >= 1; --i){
    Smallest[i] = min(Smallest[i], i - 1);
    Smallest[i] = min(Smallest[i], Smallest[i + 1]);
  }
  To -= From;
  int answer = 0;
  while(To != 0){
    To = Smallest[To];
    ++answer;
  }
  cout << answer;
  return 0;
}