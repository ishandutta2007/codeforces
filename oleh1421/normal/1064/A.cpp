#include<bits/stdc++.h>

using namespace std;

int p(long long int m){
     if (m==1) return 0;
     for (int i=2;i<=sqrt(m);i++){
          if (m%i==0) return 0;
     }
     return 1;
}
int main()
{
    long long int a,b,c,rez;
    cin>>a>>b>>c;
    if (a>=b && a>=c) if (a>=b+c) cout<<a-b-c+1;
                      else cout<<0;
    else if (b>=a && b>=c) if (b>=a+c) cout<<b-a-c+1;
                           else cout<<0;
    else if (c>=a+b) cout<<c-a-b+1;
         else cout<<0;
    return 0;
}