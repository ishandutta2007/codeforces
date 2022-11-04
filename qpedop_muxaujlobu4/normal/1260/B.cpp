#include <iostream>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
  //  vector Cost<unsigned int>
    for(int i=0;i<t;++i){
        bool ok=true;
        int a,b;
        cin>>a>>b;
        int tmp=abs(b-a);
        a=min(a,b)-tmp;
        if(a<0||a%3!=0)ok=false;
        if(ok)cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}