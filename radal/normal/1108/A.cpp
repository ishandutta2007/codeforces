#include <iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    for (int i=0; i<t; i++){ 
    long long int r1,l1,r2,l2;
    cin>>r1>>l1>>r2>>l2;
    if (l1!=l2)
    cout<<l1<<' '<<l2<<endl;
    else{
        if (r2!=l2)
    cout<<l1<<' '<<r2<<endl;
    else
    cout<<r1<<' '<<l2<<endl;
        }
    }
}