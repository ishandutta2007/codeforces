#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 1e5 + 50;
int a[maxn];
int main()
{
    int n;
    cin>> n;
    for(int i = 0; i < n; ++i){
        scanf("%d",&a[i]);
    }
    int ok = 0;
    for(int i = 1; i < n; ++i){
        if(a[i]%2 != a[i-1]%2) ok = 1;
    }
    if(ok) sort(a, a+n);
    for(int i = 0; i < n; ++i) printf("%d ",a[i]);
    cout<<endl;
}