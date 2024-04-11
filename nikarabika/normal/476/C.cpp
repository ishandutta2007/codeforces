#include <bits/stdc++.h>

using namespace std;

long long int D=1000000007;

int main(){
    unsigned long long int a, b;
    cin>>a>>b;
    unsigned long long int ans=1, t[5];
    ans=b*(b-1)/2;
    ans%=D;
    t[0]=a*(a+1)/2;
    t[0]%=D;
    t[0]*=b;
    t[0]%=D;
    t[0]+=a;
    t[0]%=D;
    ans*=t[0];
    ans%=D;
    cout<<ans<<endl;
    return 0;
}