#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,i,a[100002];
    string b[100002],c[100002];
    cin>>n;
    for(i=1;i<=n;i++){
        cin>>b[i]>>c[i];
    }
    for(i=1;i<=n;i++){
        cin>>a[i];
    }
    string temp = min(b[a[1]],c[a[1]]);
    int f=1;
    for(i=2;i<=n;i++){
        if(min(b[a[i]],c[a[i]])<temp){
            if(max(b[a[i]],c[a[i]])<temp){
                f=0;
                break;
            }
            else{
                temp = max(b[a[i]],c[a[i]]);
            }
        }
        else{
            temp=min(b[a[i]],c[a[i]]);
        }
    }
    cout<<(f?"YES":"NO");
}