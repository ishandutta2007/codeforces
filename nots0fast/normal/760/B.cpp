#include <iostream>
using namespace std;
#define lli long long int
int main()
{
    lli n , m , k;
    cin>>n>>m>>k;
    if(k<=(n+1)/2) k = n-k+1;
    lli a = 1;
    lli b = m;
    while(a!=b)
    {
        lli c = (a+b)/2+1;
        lli cem1  = (2*c-k+1)*k/2;
        if(c<k)
        {
            lli say1 = k-c;
            cem1 = say1 + c*(c+1)/2;
        }
        lli cem2 = (2*c-1-n+k)*(n-k)/2;
        if(c-(n-k)<=0)
        {
             lli say2 = (n-k)-c+1;
             cem2 = say2 +  c*(c-1)/2;
        }
        lli cem = cem1+cem2;
   //     cout<<cem1<<" "<<cem2<<" "<<cem<<" "<<c<<" "<<a<<" "<<b<<endl;
        if(cem>m)
        b = --c;
        else
        a = c;
    }
    cout<<a;
}