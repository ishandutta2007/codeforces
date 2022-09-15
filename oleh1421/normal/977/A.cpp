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
    long long int n,k;
    cin>>n>>k;
    for (int i=1;i<=k;i++){
        if (n%10==0) n/=10;
        else n--;
    }
    cout<<n;
    return 0;
}