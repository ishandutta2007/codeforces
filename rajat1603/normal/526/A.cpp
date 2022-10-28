#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define author rajat1603
#define mod 1000000007
#define N 110
int main(){
    int n;
    cin>>n;
    char arr[N]={NULL};
    cin>>arr;
    for(int i=1;i<=n;++i){
        for(int j=0;j<n;j++){
            int sz=0;
            for(int k=j;k<n;k+=i){
                if(arr[k]=='.'){
                    break;
                }
                else{
                    sz++;
                    if(sz==5){
                        printf("yes\n");
                        return 0;
                    }
                }
            }
        }
    }
    printf("no\n");
}