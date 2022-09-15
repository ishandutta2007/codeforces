#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main()
{
    int n;cin>>n;
    if (n==2){
        cout<<2<<endl<<1<<" "<<1<<endl<<2<<" "<<2<<endl;
    } else{
      int m=n/2+1;
      cout<<m<<endl;
      for (int i=1;i<=n/2;i++){
          cout<<1<<" "<<i<<endl;
      }
      for (int i=1;i<=n/2+n%2;i++){
          cout<<m<<" "<<i<<endl;
      }

    }
    return 0;
}
//1-0
//3-1
//5-2
//7 3
//9 4