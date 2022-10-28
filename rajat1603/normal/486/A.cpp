#include<iostream>
using namespace std;
int main(){
    long long n;
    cin>>n;
    cout<<(((n/2)*(4+((n/2)-1)*2))-((n-n/2)*(2 +((n-(n/2))-1)*2)))/2;

}