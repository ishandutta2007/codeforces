#include <iostream>

using namespace std;

#define rep(i, t) for(int i=0; i<t; i++)
#define FOR(i, s, e) for(int i=s; i<=e; i++)

typedef unsigned long long int ull;
typedef long long int ll;

int a[150000];
ll min_=1.5e15, min_i;

int main(){

    int n, k;
    cin>>n>>k;
    ll sum=0;
    rep(i, n){
        int t;
        cin>>t;
        sum+=t;
        sum-=a[i%k];
        a[i%k]=t;
        if(i>=k-1 && sum<min_){
            min_=sum;
            min_i=i-k+2;
        }
    }
    cout<<min_i<<endl;
    return 0;
}