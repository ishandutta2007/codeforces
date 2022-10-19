#include<bits/stdc++.h>
using namespace std;

const int maxn=107;
int n;
int a[maxn],b[maxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;++i){
        cin>>a[i];
    }
    for (int i=1;i<=n;++i){
        cin>>b[i];
    }
    int i=1;
    for (i=1;i<=n;++i){
        if (a[i]<=b[i]) continue;
        break;
    }
    if (i>n){
        cout<<-1;
        return 0;
    }
    for (int i=1;i<=101;++i){
        int sum1=0, sum2=0;
        for (int j=1;j<=n;++j){
            if (a[j]&&b[j]) continue;
            if (a[j]) sum1+=i;
            else if (b[j]) sum2+=1;
        }
        if (sum1>sum2){
            cout<<i;
            return 0;
        }
    }
    return 0;
}