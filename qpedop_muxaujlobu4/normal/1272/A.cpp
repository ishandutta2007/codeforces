#include <iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include <string>
using namespace std;
long long a[3];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    long long t;
    cin>>t;
    for(long long  i=0;i<t;++i){
        cin>>a[0]>>a[1]>>a[2];
        sort(a,a+3);
        if(a[0]==a[2]||a[0]+1==a[2]){
            cout<<0<<endl;
            continue;
        }
        ++a[0];
        --a[2];
        cout<<2*(a[2]-a[0])<<endl;
    }
    return 0;
}