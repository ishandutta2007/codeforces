#include "bits/stdc++.h"
#define ll long long
#define rep2(i,a,b) for(int i=(a);i<=(b);++i)
#define rep(i,n) rep2(i,0,n-1)
#define pii pair<int,int>
#define ti3 tuple<int,int,int>
int MOD=1000000000+7;
int INF=1e6;

using namespace std;
string alphabet("abcdefghijklmnopqrstuvwxyz");

main(){
    int n;
    cin>>n;
    int a[1100000],pos[1100000];
    rep2(i,1,n){
        scanf("%d",&a[i]);
        pos[a[i]]=i;
    }
    int swap=0;
    rep2(i,1,n){
        if(a[i]!=i){
            int temp=pos[i];
            a[temp]=a[i];
            pos[a[i]]=temp;
            swap++;
        }
    }
    if((swap%2&&n%2)||(!(swap%2)&&!(n%2))){
        cout<<"Petr";
        return 0;
    }
    cout<<"Um_nik";
    return 0;
    
}