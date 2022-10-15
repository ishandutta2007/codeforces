#include <iostream>
using namespace std;
#define ll long long
ll a,b,n,m,i,j,c,d;
int main()
{
    cin>>a>>b>>c>>d;
    if ((a+b==c+d)or(a+c==b+d)or(a+d==b+c)or(a+b+c==d)or(a+b+d==c)or(a+c+d==b)or(b+c+d==a)) cout<<"YES"; else cout<<"NO";
        
}