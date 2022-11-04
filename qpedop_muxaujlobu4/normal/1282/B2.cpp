#include <iostream>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
int a[200001];
int res[200001];
long long w[200001];
long long h[200001];
int main(){
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    h[0]=0;
    for(int i=0;i<t;++i){
       long long p;
       int k,n;
       cin>>n>>p>>k;
       for(int i=1;i<=n;++i){
            cin>>a[i];
            }
       sort(a+1,a+n+1);
       for(int i=1;i<k;++i){
           h[i]=h[i-1]+(long long)a[i];
           if(h[i]<=p){
            w[i]=h[i];
            res[i]=i;
           }
           else {
            w[i]=p+1;
            res[i]=0;
           }
       }
       res[k]=w[k]=0;
       for(int i=k;i<=n;++i){
            int tmp=i%k;
            if(tmp==0)tmp=k;
            if(w[tmp]+(long long)a[i]<=p){
                res[tmp]+=k;
                w[tmp]+=(long long)a[i];
            }
       }
       for(int i=2;i<=k;++i)res[i]=max(res[i],res[i-1]);
       cout<<res[k]<<"\n";
    }

    return 0;
}