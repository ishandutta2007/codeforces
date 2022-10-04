#include<iostream>
using namespace std;
int n,k;
int main(){
    cin>>n>>k;
    cout<<n+k-n%k;
    return 0;
}