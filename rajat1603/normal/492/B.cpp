#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int n,l;
    cin>>n>>l;
    int a[1001];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    int m=0;
    for(int i=0;i<n-1;i++){
        m=max(m,a[i+1]-a[i]);
    }
    m=max(a[0]*2,m);
    m=max((l-a[n-1])*2,m);
    if(m&1){
        cout<<m/2<<".5";
    }
    else{
        cout<<m/2;
    }
}