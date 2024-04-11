#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
#define endl '\n'
const int N=100055;
double a[N];

void solve(){
    int n,l;cin>>n>>l;
    for (int i=1;i<=n;i++) cin>>a[i];
    a[0]=0;
    a[n+1]=l;
    double L=0.0;
    double R=l*1.0;
    for (int it=1;it<=100;it++){
        double mid=(L+R)/2.0;
        double T1=0.0;
        for (int i=1;i<=n+1;i++){
            if (a[i]<=mid){
                T1+=(a[i]-a[i-1]+0.0)/(i*1.0);
            } else {
                T1+=(mid-a[i-1]*1.0)/(i*1.0);
                break;
            }
        }
        double T2=0.0;
        for (int i=n;i>=0;i--){
            if (a[i]>=mid){
                T2+=(a[i+1]-a[i]+0.0)/(n-i+1.0);
//                cout<<"OK "<<a[i+1]<<" "<<a[i]<<" "<<(a[i+1]-a[i]+0.0)/(n-i+1.0)<<endl;
            } else {
                T2+=(a[i+1]-mid+0.0)/(n-i+1.0);
//                cout<<a[i+1]-mid<<endl;
                break;
            }
        }
//        cout<<mid<<" "<<T1<<" "<<T2<<endl;
//        cout<<T2<<endl;
        if (T1<T2) L=mid;
        else R=mid;
    }
    double mid=(L+R)/2.0;
//    cout<<mid<<endl;

    double T1=0.0;
    for (int i=1;i<=n+1;i++){
        if (a[i]<=mid){
            T1+=(a[i]-a[i-1]+0.0)/(i*1.0);
        } else {
            T1+=(mid-a[i-1]*1.0)/(i*1.0);
            break;
        }
    }
    cout<<setprecision(10)<<fixed<<T1<<endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}