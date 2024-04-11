#include <bits/stdc++.h>
#define f first
#define s second

using namespace std;
int main()
{
    long long n;
    cin>>n;
    //a(n) = 4 + floor((4*n-3)/3)
    if(n==1){
        cout<<3;
        return 0;
    }
    cout<<4+(4*n-3)/3;
}