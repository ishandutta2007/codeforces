#include "bits/stdc++.h"
#define ll long long
#define rep2(i,a,b) for(int i=(a);i<=(b);++i)
#define rep(i,n) rep2(i,0,n-1)
int MOD=1000000000+7;
int INF=1e6;
 
using namespace std;
string alphabet("abcdefghijklmnopqrstuvwxyz");

main(){
    int n,k;
    cin>>n>>k;
    int a[256]={};
    int pos=1;
    rep(i,n){
        int b;
        cin>>b;
        int g=b;
        if(a[b]==0){
            rep(j,k){
                if(a[b]!=0){
                    int mem=a[b];
                    int c=b;
                    while(a[c]==mem&&c>=0){
                        c--;
                        j++;
                    }
                    if(j<=k){
                        b=c;
                        rep2(j,b+1,g) a[j]=mem;
                    }
                    pos++;
                    break;
                }
                if(b==-1) break;
                a[b]=pos;
                b--;
            }
            pos++;
            cout<<b+1<<" ";
        }
        else{
            int mem=a[b];
            while(a[b]==mem&&b>=0){
                b--;
            }
            cout<<b+1<<" ";
        }
    }
    return 0;
}