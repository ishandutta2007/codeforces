#include <iostream>
#include <cmath>
using namespace std;
int main(){
    long long a00, a01, a10, a11, cnt0, cnt1, tot;
    cin>>a00>>a01>>a10>>a11;
    if(!a00&&!a01&&!a10&&!a11){
        cout<<0<<endl;
        return 0;
    }
    cnt0=1+0.5*sqrt(1+8*a00);
    cnt1=1+0.5*sqrt(1+8*a11);
    if((cnt0-1)*cnt0!=2*a00||(cnt1-1)*cnt1!=2*a11){
        cout<<"Impossible"<<endl;
        return 0;
    }
    if(!a01&&!a10){
        if(cnt0==1) cnt0--;
        if(cnt1==1) cnt1--;
    }
    tot=cnt0+cnt1;
    if(cnt0*cnt1!=a01+a10){
        cout<<"Impossible"<<endl;
        return 0;
    }
    for(long long i=0; i<tot; i++){
        if(a01>=cnt1){
            cnt0--;
            a01-=cnt1;
            cout<<0;
        }else{
            cnt1--;
            cout<<1;
        }
    }
    cout<<endl;
    return 0;
}