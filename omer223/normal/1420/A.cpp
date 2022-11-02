#include <iostream>
using namespace std;

int a[100000];

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        for(int i = 0; i < n; i++)cin>>a[i];
        bool x = 1;
        for (int i = 1; i < n; i++){
            if(a[i]>=a[i-1])x=0;
        }
        cout<<(!x?"YES":"NO")<<endl;
    }
    return 0;
    
}