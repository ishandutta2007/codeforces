#include <iostream>

using namespace std;

int main()
{
    int sum1=0, sum2=0;
    int a, b, c, n;
    cin>>a>>b>>c;
    sum1=a+b+c;
    cin>>a>>b>>c;
    sum2=a+b+c;
    cin>>n;
    int a1,a2;
    a1=sum1/5;
    if(sum1%5)
        a1++;
    a2=sum2/10;
    if(sum2%10)
        a2++;
    if(n<a1+a2)
        cout<<"NO"<<endl;
    else
        cout<<"YES"<<endl;
    return 0;
}