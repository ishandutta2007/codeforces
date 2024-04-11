#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
#define endl '\n'
const int N=500010;
const int inf=1000000001;
int a[N];
void solve(){
    int n;cin>>n;
    int sum=0;
    for (int i=1;i<=n;i++) cin>>a[i],sum+=a[i];
    if (sum%n){
        cout<<-1<<endl;
        return;
    }
    int X=sum/n;
    vector<pair<pair<int,int>,int> >v;
    for (int i=2;i<=n;i++){
        v.push_back({{1,i},(i-a[i]%i)%i});
        v.push_back({{i,1},(a[i]+(i-a[i]%i)%i)/i});
    }
    for (int i=2;i<=n;i++){
        v.push_back({{1,i},X});
    }
    cout<<v.size()<<endl;
    for (auto cur:v){
        int i=cur.first.first;
        int j=cur.first.second;
        int x=cur.second;
        a[i]-=i*x;
        a[j]+=i*x;
        cout<<cur.first.first<<" "<<cur.first.second<<" "<<cur.second<<endl;
    }
//    for (int i=1;i<=n;i++) cout<<a[i]<<" ";
//    cout<<endl;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}
/*
8 7
1 7 5 6 8 2 6 5

*/