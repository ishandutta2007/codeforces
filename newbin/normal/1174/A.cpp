#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 1e5 + 50;
int a[maxn];
int main()
{
    int n;
    cin>> n;
    ll sum = 0;
    for(int i = 0; i < 2*n; ++i){
        scanf("%d",&a[i]);
        sum += a[i];
    }
    sort(a, a+2*n);
    ll t = 0;
    for(int i = 0; i < n; ++i) t += a[i];
    if(2*t == sum){
        cout<<-1<<endl;return 0;
    }
    for(int i = 0; i < 2*n; ++i) printf("%d ",a[i]);
    cout<<endl;
}