#include <iostream>
#include<map>
#include<string>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
int a[1000];
int main(){
    ios_base::sync_with_stdio(false);
    int n,m,d,PLong=0;
    cin>>n>>m>>d;
    for(int i=0;i<m;++i){
        cin>>a[i];
        PLong+=a[i];
        }
    if((m+1)*(d-1)+PLong>=n)cout<<"YES\n";
    else{
        cout<<"NO";
        return 0;
    }
    int ValMinLong=(n-PLong)/(m+1),CtMaxLong=(n-PLong)%(m+1),k=1;
    if(CtMaxLong==0)
        for(int i=0;i<ValMinLong;++i)
            cout<<0<<" ";
    else{
        for(int i=0;i<=ValMinLong;++i)
            cout<<0<<" ";
        --CtMaxLong;
    }
    for(int i=0;i<m;++i){
      for(int j=0;j<a[i];++j)
            cout<<k<<" ";
      ++k;
      if(CtMaxLong==0){
        for(int j=0;j<ValMinLong;++j)
            cout<<0<<" ";
      }
      else{
        for(int j=0;j<=ValMinLong;++j)
            cout<<0<<" ";
        --CtMaxLong;
      }
    }
    return 0;
}