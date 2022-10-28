#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
int main(){
    int n,m;
    bool happya[101]={0};
    bool happyb[101]={0};
    int b;
    cin>>n>>m;
    cin>>b;
    while(b--){
        int temp;
        cin>>temp;
        happya[temp]=1;
    }
    cin>>b;
    while(b--){
        int temp;
        cin>>temp;
        happyb[temp]=1;
    }
    for(int i=0;i<=10000000;i++){
        int x=i%n;
        int y=i%m;
        bool z= happya[x];
        z|=happyb[y];
        happya[x]=z;
        happyb[y]=z;
    }
    bool ans=1;
    for(int i=0;i<n;i++){
        ans&=happya[i];
    }
    for(int i=0;i<m;i++){
        ans&=happyb[i];
    }
    if(ans){
        cout<<"Yes";
    }
    else{
        cout<<"No";
    }
}