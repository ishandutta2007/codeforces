#include<iostream>
#include<cstdio>

using namespace std;

int main(){
    int n, a[100000];
    cin>>n;

    for(int i=0; i<n; i++)scanf("%d", a+i);

    long long t=0;

    for(int i=0; i<n-1; i++){
        int j;
        for(j=1; i+2*j<n; j*=2);
        t+=a[i];
        a[i+j]+=a[i];
        a[i]=0;
        cout<<t<<endl;
    }
    return 0;
}