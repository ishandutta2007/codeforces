#include <bits/stdc++.h>

using namespace std;
int n;
int ask(int x)
{
    cout << "? " << x << endl;
    cout << "? " << x + n / 2 << endl;
    int a,b;
    cin >> a >> b;
    if(a == b){
        printf("! %i\n",x);
        exit(0);
    }
    return a < b;
}
int main()
{
    ios_base::sync_with_stdio(0);
    scanf("%i",&n);
    if((n/2)%2==1)
    {
        printf("! -1\n");
        return 0;
    }
    int pola=n/2;
    int a=1;
    int b=1+pola;
    int s=ask(1);
    while(true)
    {
        int m=(a+b)/2;
        if(ask(m)==s)
        {
            a=m;
        }
        else
        {
            b=m;
        }
    }
    return 0;
}
/*
int n;
int ask(int x){
  cout << "? " << x << endl;
  cout << "? " << x + n / 2 << endl;
  int a,b;
  cin >> a >> b;
  if(a == b){
    cout << "! " << x << endl;
    exit(0);
  }
  return a < b;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  cin >> n;
  if(n % 4 == 2){
    cout << "! -1\n";
    return 0;
  }
  int po = 1;
  int ko = 1 + n/2;
  int jak = ask(1);
  while(1){
    int m = (po + ko) / 2;
    if(ask(m) == jak){
      po = m;
    }else{
      ko = m;
    }
  }
}
*/