#include <bits/stdc++.h>
using namespace std;
int n,b,p;
int main(){
    cin >> n >> b >> p;
    int E[10];
    E[1]=2;
    int s=0,s2=n*p;
    b=b*2+1;
    for(int i=2;i<=9;i++)E[i]=E[i-1]*2;
    while(n>1){
        int i;
        for(i=1;E[i+1]<=n;i++);
        s+=b*(E[i]/2);
        n-=E[i]/2;
        //cout<<E[i]<<endl;
    }
    //cout<<b;
    cout<<s<<" "<<s2;
}