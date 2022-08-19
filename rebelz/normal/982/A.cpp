#include<iostream>

using namespace std;

int n;
char c[100005];

int main(){
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>c[i];
    if(n==1&&c[1]=='0'){
        cout<<"No"<<endl;
        return 0;
    }
    if(c[1]=='0'&&c[2]=='0'){
        cout<<"No"<<endl;
        return 0;
    }
    if(c[n-1]=='0'&&c[n]=='0'){
        cout<<"No"<<endl;
        return 0;
    }
    for(int i=1;i<=n;i++){
        if(c[i]=='0'&&c[i-1]=='0'&&c[i+1]=='0'){
            cout<<"No"<<endl;
            return 0;
        }
        else if(c[i]=='1'&&c[i-1]=='1'){
            cout<<"No"<<endl;
            return 0;
        }
    }
    cout<<"Yes"<<endl;
    return 0;
}