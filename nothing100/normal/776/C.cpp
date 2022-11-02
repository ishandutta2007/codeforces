#include<bits/stdc++.h>
#define LL long long
#define mo 1594323
using namespace std;
int n,k;
LL a[100010],ans;
map<LL,int> ma;
int main(){
    scanf("%d%d",&n,&k);
    for (int i=0;i<n;i++) scanf("%lld",&a[i]);
    for (int i=1;i<n;i++) a[i]+=a[i-1];
    ma[0]++;
    for (int i=0;i<n;i++){
        ma[a[i]]++;
        if (k==1) ans+=ma[a[i]-k];
        else if (k==-1){
            ans+=ma[a[i]-1];
            ans+=ma[a[i]+1];
        }
        else{
            for (LL j=1;j<1000000000000000LL;j*=k) ans+=ma[a[i]-j];
        }
    }
    printf("%lld\n",ans);
    return 0;
}