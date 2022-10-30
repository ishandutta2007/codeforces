#include <iostream>
#include <algorithm>

using namespace std;

const int sz=1e5+5;
int a[sz];

int main(){
    int n;
    bool o=0,e=0;
    cin>>n;
    for(int i =0;i<n;i++){
        cin>>a[i];
        if(a[i]&1)o=1;
        else e=1;
    }
    if(o&&e)sort(a,a+n);
    for(int i =0;i<n;i++)cout<<a[i]<<" ";
    cout<<endl;
}