#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
int main(){
    int a,b,s;
    cin>>a>>b>>s;
    int mini = abs(a)+abs(b);
    if(s<mini){
        cout<<"No";
        return 0;
    }
    if((s-mini)%2==0){
        cout<<"Yes";
        return 0;
    }
    cout<<"No";
}