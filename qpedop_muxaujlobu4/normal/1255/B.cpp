#include <iostream>
#include<map>
#include<string>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
int b[2001];
int main(){
    ios_base::sync_with_stdio(false);
    int T,n,m;
    cin>>T;
    for(int i=0;i<T;++i){
        cin>>n>>m;
        long long cost=0,ind1=-1,ind2=-1,min1=100000,min2=100000;
        for(int j=1;j<=n;++j){
            cin>>b[j];
            cost+=b[j];
            if(b[j]<=min1){
                ind2=ind1;
                ind1=j;
                min2=min1;
                min1=b[j];
            }
            else if(b[j]<=min2){min2=b[j];ind2=j;}
        }
        if(m<n||n==2){cout<<"-1\n";continue;}

        //if(n==2){
        //    cost*=m;
         //   cout<<cost<<"\n";
         //   for(int j=0;j<m;++j)
         //       cout<<1<<" "<<2<<"\n";
         //   continue;
       // }

        cost*=2;
        cost+=(min2+min1)*(m-n);
        cout<<cost<<"\n";
        for(int j=1;j<n;++j)
            cout<<j<<" "<<j+1<<"\n";
        cout<<1<<" "<<n<<"\n";
        m-=n;
        for(int j=0;j<m;++j)
            cout<<ind1<<" "<<ind2<<"\n";
    }
    return 0;
}