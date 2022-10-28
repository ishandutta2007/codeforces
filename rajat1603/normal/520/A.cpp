#include<bits/stdc++.h>
using namespace std;
#define author rajat1603
#define mod 1000000007
#define pb push_back
#define mp make_pair
int main(){
    int n;
    cin>>n;
    char a[201]={NULL};
    cin>>a;
    bool b[1001]={0};
    for(int i=0;i<n;i++){
        if(a[i]>='a'){
            a[i]-=32;
        }
        b[a[i]-'A']=1;
    }
    for(int i=0;i<26;i++){
        if(b[i]==0){
            cout<<"NO";
            return 0;
        }
    }
    cout<<"YES";
}