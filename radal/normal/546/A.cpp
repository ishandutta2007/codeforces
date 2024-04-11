
#include <iostream>
using namespace std;
int main(){
    long long int w,n,k;
    cin>>k>>n>>w;
    if (n>=k*w*(w+1)/2){
        cout<<0;
    }
    else{
        cout<<k*w*(w+1)/2-n;
    }
}