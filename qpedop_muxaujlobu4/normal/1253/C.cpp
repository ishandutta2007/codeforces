#include <iostream>
#include<map>
#include<string>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
int a[200000];
int main(){
    ios_base::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;++i)
        cin>>a[i];
    sort(a,a+n);
    vector<long long> b(m,0);
    vector<long long> c(m,0);
    long long res=0;
    for(int i=0;i<n;++i){
        int ind = i%m;
        res-=b[ind];
        c[ind]+=a[i];
        b[ind]+=c[ind];
        res+=b[ind];
        cout<<res<<" ";
    }
    return 0;
}