#include <iostream>

using namespace std;

int a[100005],n,x,y;

bool is(int i) {
    bool ans=true;
    for(int j = 1;j<=x&&i-j>=0;j++){
        ans&=a[i]<a[i-j];
    }
    for(int j = 1;j<=y&&i+j<n;j++){
        ans&=a[i]<a[i+j];
    }
    return ans;
}

int main() {
    cin>>n>>x>>y;
    for(int i =0;i<n;i++){
        cin>>a[i];
    }
    for(int i =0;i<n;i++){
        if(is(i)){
            cout<<i+1<<endl;
            break;
        }
    }
    return 0;
}