#include <iostream>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
long long a[200001];
long long res[2];
long long w[2];
int main(){
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    for(int i=0;i<t;++i){
       long long p;
       int k,n;
       cin>>n>>p>>k;
       for(int i=1;i<=n;++i)cin>>a[i];
       sort(a+1,a+n+1);
       res[0]=res[1]=w[0]=w[1]=0;
       for(int i=1;i<=n;++i){
        if(i%2==1){
            if(w[1]+a[i]<=p){
                w[1]+=a[i];
                ++res[1];
            }
        }
        else{
           if(w[0]+a[i]<=p){
            w[0]+=a[i];
            ++res[0];
           }
        }
       }
       cout<<max(res[0]*2,res[1]*2-1)<<"\n";
    }

    return 0;
}