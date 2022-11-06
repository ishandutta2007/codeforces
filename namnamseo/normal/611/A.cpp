#include <iostream>
#include <string>
using namespace std;

int dim[13] = {0, 31, 29, 31, 30, 31, 30,31,31,30,31,30,31};

int main()
{
    int n; string t;
    cin>>n>>t>>t;
    int y=2016, m=1, d=1, dt=5, ans=0;
    for(;y!=2017;){
        if(t[0]=='w'){
            if(n==dt) ++ans;
        } else {
            if(n==d) ++ans;
        }
        ++dt;
        if(dt==8) dt=1;
        ++d;
        if(d==dim[m]+1) ++m, d=1;
        if(m==13) m=1, ++y;
    }
    cout<<ans;
    return 0;
}