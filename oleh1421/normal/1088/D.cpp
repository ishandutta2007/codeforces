#include <bits/stdc++.h>
//#define int long long
#define MINX(a,b) if(a>b) a=b;
typedef long long ll;
using namespace std;
int ask(int a,int b){
    cout<<"? "<<a<<" "<<b<<endl;
    int x;cin>>x;
    return x;
}
int32_t main()
{
    cout.flush();
    int a=0;
    int b=0;
    int big=ask(0,0);
    for (int i=29;i>=0;i--){
        int f=ask(a^(1<<i),b);
        int s=ask(a,b^(1<<i));
        if (s==f){
            if (big==1) a^=(1<<i);
            else b^=(1<<i);
            big=f;
        } else if (f==-1){
            a^=(1<<i);
            b^=(1<<i);
        }
    }
    cout<<"! "<<a<<" "<<b<<endl;
    return 0;
}
//2 6 -2 -6  2