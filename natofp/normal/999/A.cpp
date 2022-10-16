#include <iostream>

using namespace std;

int main()
{
    int n,k;
    cin>>n>>k;
    int * p;
    p=new int[n];
    for(int i=0;i<n;i++)
        cin>>p[i];
    int a=0;
    int b=n-1;
    int w=0;
    while(a<n && p[a]<=k) {a++; w++;}
    while(b>=0 && b>=a && p[b]<=k) {b--; w++;}
    cout<<w;
    return 0;
}