#include<bits/stdc++.h>

using namespace std;

typedef long long LL;

LL qry(LL x,LL y){
    cout<<"? "<<x<<' '<<y<<'\n';
    fflush(stdout);
    LL t; cin>>t;
    return t;
}

void ans(LL x){
    cout<<"! "<<x<<'\n';
    fflush(stdout);
    exit(0);
}

int main(){
    for (LL i=2;i<=26;++i){
        LL x1=qry(1,i);
        LL x2=qry(i,1);
        if (x1==-1){
            ans(i-1);
        }
        if (x1!=x2){
            ans(x1+x2);
        }
    }

    return 0;
}