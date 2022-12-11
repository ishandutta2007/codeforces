#include <bits/stdc++.h>
#define f first
#define s second

using namespace std;

int main()
{
    long long n,m;
    cin>>n>>m;
    if(m==1){
        cout<<n-1;
    }else{
        cout<<n*(m-1);
    }
}