#include <bits/stdc++.h>
using namespace std;
ifstream fi("STRING.INP");
ofstream fo("STRING.OUT");
const int maxN=2e5+5;
struct get{
    int gt;
    int cs;
}A[maxN];int n;
bool ss(get A,get B){
    return (A.gt>B.gt);
}
void enter(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>A[i].gt;
        A[i].cs=i;
    }
}
void solve(){
    sort(A+1,A+n+1,ss);
    long long s=0;
    for(int i=2;i<=n;i++)
        s+=abs(A[i].cs-A[i-1].cs);
    cout<<s;
}
int main(){
    enter();
    solve();
}