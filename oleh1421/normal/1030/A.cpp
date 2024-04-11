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
    long long int n,k,s;
    cin>>n;
    s=0;
    for (int i=1;i<=n;i++){
        cin>>k;
        s+=k;
    }
    if (s>0) cout<<"HARD";
    else cout<<"EASY";
    return 0;
}