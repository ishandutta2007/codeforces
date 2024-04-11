#include <iostream>
#include<map>
#include<string>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    int a,b,k;
    cin>>k;
    for(int i=0;i<k;++i){
        cin>>a>>b;
        if(a==b){cout<<0<<"\n";continue;}
        int k=0;
        if(a>b){
           b=a-b;
            k=b/5;
            b%=5;
            if(b>2)k+=2;
            else if (b>0)++k;
        }
        else{
            b=b-a;
            k=b/5;
            b%=5;
            if(b>2)k+=2;
            else if (b>0)++k;
        }
        cout<<k<<"\n";
    }
    return 0;
}