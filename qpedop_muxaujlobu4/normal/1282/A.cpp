#include <iostream>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    for(int i=0;i<t;++i){
        long long a,b,c,r;
        cin>>a>>b>>c>>r;
        if(b<a){
            long long tmp=a;
            a=b;
            b=tmp;
        }
        if(c+r<=a||c-r>=b){
            cout<<b-a<<"\n";
            continue;
        }
        if(c+r>b){
            long long res=c-r-a;
            if(res<0)res=0;
            cout<<res<<"\n";
        }
        else {
            if(c-r<a){
                long long res=b-(c+r);
                if(res<0)res=0;
                cout<<res<<"\n";
            }
            else{
                long long res=c-r-a+(b-(c+r));
                cout<<res<<"\n";
            }
        }
    }
    return 0;
}