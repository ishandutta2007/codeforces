#include <iostream>
#include <algorithm>
using namespace std;

int arr[100010];
int b[100010];
int test;
bool comp(int x, int y){
    if(arr[x]>=arr[y])return false;
    return true;
}
bool evens(int ini, int current){
    return (ini-current)%2==0;
}
void solve(){
    int n;
    cin>>n;
    
    for(int i = 0;i<n;i++){
        int buff;
        cin>>buff;
        arr[i] = buff;
        b[i] = i;
    }
    
    sort(b,b+n,comp);
    
    bool accepted = true;
    for(int i = 0;i<n;i++){
        if(evens(b[i],i))continue;
        for(int j = i+1;j<n;j++){
            if(arr[b[i]]!=arr[b[j]]){
                accepted=false;
                break;
            }
            if(evens(b[j],i)){
                swap(b[i],b[j]);
                break;
            }
        }
        if(!accepted)break;
    }
    if(accepted){
        cout<<"YES\n";
    }else{
        cout<<"NO\n";
    }
}

int main(){
    
    cin>>test;
    while(test--)solve();
}