#include <iostream>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
  //  vector Cost<unsigned int>
    for(int i=0;i<n;++i){
        unsigned long long c,sum,res=0;
        cin>>c>>sum;
        unsigned long long CtMaxCost=sum%c,CostMN=sum/c;
        unsigned long long CtMinCost=c-CtMaxCost;
        res=CtMinCost*CostMN*CostMN+CtMaxCost*(CostMN+1)*(CostMN+1);
        cout<<res<<"\n";
    }
    return 0;
}