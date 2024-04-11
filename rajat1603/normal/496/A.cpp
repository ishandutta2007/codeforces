#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a[1000];
    int maxi=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(i>=2){
            maxi=max(maxi,a[i]-a[i-1]);
        }
    }
    int mini=1000;
    for(int i=1;i<=n-2;i++){
        mini=min(mini,a[i+2]-a[i]);
    }
    cout<<max(maxi,mini);
}