#include <iostream>

using namespace std;
typedef unsigned long long ll;

int main()
{
    ll a,b;
    cin>>a>>b;
    int len, pos, ans=0;
    for(len=2;len<=63;++len){
        for(pos=0;pos<len-1;++pos){
            ll tmp = (1ull<<len)-1-(1ull<<pos);
            if(a<=tmp && tmp<=b) ++ans;
        }
    }
    cout<<ans;
    return 0;
}