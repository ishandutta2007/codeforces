#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int n,m,i,k=0;
    long long a[100001]={0};
    cin>>n;
    for(i=0;i<n;i++){
        cin>>m;
        a[m] += m;
        k=max(k,m+1);
    }
    for(i=2;i<k;i++){
        a[i] += a[i-2];
        if(a[i - 1] > a[i]){
            a[i] = a[i-1];
        }
    }
    cout<<a[k-1]<<endl;
}