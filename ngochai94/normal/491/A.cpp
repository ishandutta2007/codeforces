#include <bits/stdc++.h>
using namespace std;

int a,b;

int main()
{
    //freopen("input.txt","r",stdin);
    ios::sync_with_stdio(0);
    cin>>a>>b;
    int n=a+b+1;
    for (int i=0;i<a;i++) cout<<i+1<<' ';
    cout<<n<<' ';
    for (int i=n-1;i>a;i--) cout<<i<<' ';
    return 0;
}