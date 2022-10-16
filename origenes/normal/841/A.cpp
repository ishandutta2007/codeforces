#include <bits/stdc++.h>
using namespace std;
int main(){
    int c[30];
    int n, k;
    memset(c, 0, sizeof(c));
    cin>>n>>k;
    cin.get();
    for(int i=0; i<n; i++){
        char tmp=cin.get();
        c[tmp-'a']++;
        if(c[tmp-'a']>k){
            cout<<"NO"<<endl;
            return 0;
        }
    }
    cout<<"YES"<<endl;
    return 0;
}