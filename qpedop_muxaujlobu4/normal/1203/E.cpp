#include <iostream>
#include<map>
#include<string>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    vector <int> a(n);
    vector<bool>b(150002,false);
    for(int i=0;i<n;++i)
        cin>>a[i];
    sort(a.begin(),a.end());
    b[0]=true;
    int k=0;
    for(int i=0;i<n;++i){
        if(b[a[i]-1]==false){
            b[a[i]-1]=true;
            ++k;
        }
        else{
           if(b[a[i]]==false){
            b[a[i]]=true;
            ++k;
           }
           else{
            if(b[a[i]+1]==false){
                b[a[i]+1]=true;
                ++k;
            }
           }
        }
    }
    cout<<k;
    return 0;
}