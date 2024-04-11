#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int i=0;
    int sum=0;
    while(sum<=n){
        sum+=(i*(i+1)/2);
        i++;
    }
    cout<<i-2;
}