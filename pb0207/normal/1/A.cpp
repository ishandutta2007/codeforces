#include<iostream>
using namespace std;

long long n,m,a;

int main()
{
    cin>>n>>m>>a;
    cout<<(n/a+!(n%a==0))*(m/a+!(m%a==0));
}