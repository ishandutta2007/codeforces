#include<bits/stdc++.h>
using namespace std;
#define author rajat1603
#define MOD 1000000007
#define pb push_back
#define mp make_pair
int main(){
    int n,t;
    cin>>n>>t;
    int a[30001];
    for(int i=1;i<n;i++){
        scanf("%d",a+i);
    }
    int pos=1;
    a[n]=1;
    while(pos<=t){
        if(pos==t){
            cout<<"YES\n";
            return 0;
        }
        pos+=a[pos];
    }
    cout<<"NO";
}