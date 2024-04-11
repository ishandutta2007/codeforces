#include <bits/stdc++.h>
#define f first
#define s second

using namespace std;
long long mas[100005];
int main()
{
    long long n,d;
    cin>>n>>d;
    long long ans=0;
    for(long long i=0; i<n; i++){
        cin>>mas[i];
    }
    sort(mas,mas+n);
    long long used=0;
    for(long long i=n-1; i>=0; i--){
        long long a=(d+mas[i])/mas[i];
        if(used+a>n){
            break;
        }else{
            used+=a;
            ans++;
        }
    }
    cout<<ans;
}