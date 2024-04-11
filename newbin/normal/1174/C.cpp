#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 1e5 + 50;
int a[maxn];
int main()
{
    int tot = 0;
    int n; cin>> n;
    for(int i = 2; i <= n; ++i){
        if(a[i]) continue;
        a[i] = ++tot;
        for(int j = 2*i; j <= n; j += i){
            if(!a[j]) a[j] = tot;
        }
    }
    for(int i = 2; i <= n; ++i) printf("%d ",a[i]);
    cout<<endl;
}