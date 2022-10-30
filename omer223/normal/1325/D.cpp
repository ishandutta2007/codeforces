#include <iostream>

using namespace std;
typedef long long ll;
int main() {
    ll x,s;
    cin>>x>>s;
    if(x==s){
        if(!x){
            cout<<0<<endl;
        }
        else {
            cout<<1<<endl<<x<<endl;
        }
    }
    else if (x>s||(s&1)!=(x&1)){
        cout<<-1<<endl;
    }
    else {
        ll k = (s-x)>>1;
        if(!(k&x)){
            cout<<2<<endl;
            cout<<(x|k)<<" "<<k<<endl;
        }
        else {
            cout<<3<<endl;
            cout<<x<<" "<<k<<" "<<k<<endl;
        }
    }
    return 0;
}