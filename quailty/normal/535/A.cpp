#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
string x[10]={"zero","one","two","three","four","five","six","seven","eight","nine"};
string y[10]={"","","twenty","thirty","forty","fifty","sixty","seventy","eighty","ninety"};
string p[10]={"ten","eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen"};
int main()
{
    int s;
    cin>>s;
    if(s<10)cout<<x[s]<<endl;
    else if(s>=10 && s<20)cout<<p[s-10]<<endl;
    else if(s%10==0)cout<<y[s/10]<<endl;
    else cout<<y[s/10]<<"-"<<x[s%10]<<endl;
    return 0;
}